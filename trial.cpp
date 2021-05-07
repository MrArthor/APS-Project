#include <bits/stdc++.h>
#include <windows.h>

using namespace std;
int SourceFileList();
int AddSourceFile(string, string);
void loading()
{

    for (int i = 0; i < 5; i++)
    {
        cout << "****";
        Sleep(1000);
    }
}
//yaha par kiya h add
float rabinKarp(char seq[], char arr[], int line, int sent_line)
{
    //seq is the sentence of the input text and arr corresponds to lines of the output file.
    int m = 121;
    int d = 256;
    int y;
    int len1 = strlen(seq);
    int hash_1 = 0;
    int len2 = strlen(arr);
    int hash_2 = 0;
    int h = 1;
    int l = 0;

    for (int x = 0; x < len1 - 1; x++)
    {
        h = (h * d) % m;
    }

    //For calculating the hash code value.
    for (int x = 0; x < len1; x++)
    {
        hash_1 = (d * hash_1 + seq[x]) % m;
        hash_2 = (d * hash_2 + arr[x]) % m;
    }

    for (int x = 0; x <= len2 - len1; x++)
    {
        if (hash_1 == hash_2)
        {
            for (y = 0; y < len1; y++)
            {
                if (seq[y] != arr[x + y])
                    break;
            }

            if (y == len1)
            {
                l++;
                //   cout << "Sentence " << sent_line << " of the input text found at line " << line << " of output file" << std::endl;
                break;
            }
        }

        else if (x < len2 - len1)
        {
            int w = d * (hash_2 - arr[x] * h);
            hash_2 = (w + arr[x + len1]) % m;

            if (hash_2 < 0)
            {
                hash_2 = (hash_2 + m);
            }
        }
    }
    return l;
}
int PlagChecker(string TopicName = "Russia", string FileName = "inputtest")
{
    ifstream SourceFile;
    SourceFile.open("Sources/" + TopicName + ".txt");
    string SourceFileText;
    string SourceFileContent;
    while (getline(SourceFile, SourceFileText))
    {
        SourceFileContent += SourceFileText;
    }
    SourceFile.close();
    istringstream iss(SourceFileContent);
    string strtest;
    string TestData = "";
    int line;
    float q = 0;
    float p = 0;
    float total_line = 0;
    float match_line = 0;
    while (getline(iss, strtest, '.'))
    {
        if (!strtest.empty())
        {
            total_line++;
            line = 1;
            int m = strtest.length();
            char seq[m + 1];
            strcpy(seq, strtest.c_str());
            ifstream file;
            file.open(FileName + ".txt");
            string st1;
            while (getline(file, st1))
            {
                int n = st1.length();
                char char_array[n + 1];
                strcpy(char_array, st1.c_str());
                q = rabinKarp(seq, char_array, line, total_line);
                line++;
                if (q > 0)
                    p++;
            }
            file.close();

            if (p > 0)
                match_line++;
        }
        p = 0;
    }
    ifstream file;
    file.open(FileName + ".txt");
    string st1;
    while (getline(file, st1))
    {
        TestData += st1 + "\n";
    }
    ofstream myfile;
    myfile.open("output.txt");
    float plag;
    if (total_line == 0)
    {
        plag = 0;
    }
    else
        plag = 100 * (match_line / total_line);
    cout << " " << std::endl;
    myfile << "Total match sentence in the given input text is " << match_line << " and total sentence in the given input text is " << total_line << std::endl;
    cout << "Total match sentence in the given input text is " << match_line << " and total sentence in the given input text is " << total_line << std::endl;
    if (plag > 70)
    {
        myfile << "The give file has significant amount of Plagarism and it is " << plag << " %" << std::endl;
        cout << "The give file has significant amount of Plagarism and it is " << plag << " %" << std::endl;
    }
    else
    {
        myfile << "Plagarism is not detected in the given file and it is " << plag << " %" << std::endl;
        cout << "Plagarism is not detected in the given file and it is " << plag << " %" << std::endl;
    }
    if (plag == 0)
    {
        cout << TestData;
        AddSourceFile(TopicName, TestData);
    }
    cout << " " << std::endl;
    return 0;
}
//yaha par
int SourceFileList()
{
    int NumberOfFiles = 0;
    ifstream myfile;
    myfile.open("Sources/FileList.txt");
    string st1;
    while (getline(myfile, st1))
    {
        cout << st1 << ", ";
        NumberOfFiles++;
    }
    cout << endl;
    return NumberOfFiles;
}
//aur yaha par bas
int AddSourceFile(string FileName, string Content)
{
    int NumberOfFiles = 0;
    ofstream myfile;
    myfile.open("Sources/FileList.txt", ios::app);
    myfile << endl
           << FileName;
    cout << endl;
    myfile.close();
    ofstream file;
    file.open("Sources/" + FileName + ".txt", ios::app);
    file << endl
         << Content;

    file.close();
    return 0;
}

const int ALPHABET_SIZE = 26;

// trie node
class TrieNode
{
public:
    TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;

    TrieNode()
    {
        this->isEndOfWord = false;

        for (int i = 0; i < ALPHABET_SIZE; i++)
            this->children[i] = NULL;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode;
    }

    // If not present, inserts key into trie
    // If the key is prefix of trie node, just
    // marks leaf node
    void insert(string key)
    {
        TrieNode *pCrawl = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            cout << "TEST " << index << " " << key[i] << endl;
            if (!pCrawl->children[index])
                pCrawl->children[index] = new TrieNode;
            pCrawl = pCrawl->children[index];
        }

        // mark last node as leaf
        pCrawl->isEndOfWord = true;
    }

    // Builds Trie for helping out spam word search
    void build(vector<string> arr)
    {
        //print(arr);
        for (auto ele : arr)
        {
            this->insert(ele);
        }
    }

    // Returns true if key presents in trie, else
    // false
    bool search(string key)
    {
        TrieNode *pCrawl = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                return false;

            pCrawl = pCrawl->children[index];
        }

        return (pCrawl != NULL && pCrawl->isEndOfWord);
    }

} Spam;

// Retrive spam words from database
vector<string> retrieve(string FileName = "SpamWords")
{

    // stores distinct words;
    vector<string> words;

    // Reading words from stored file
    ifstream spam_words;
    spam_words.open("Sources/" + FileName + ".txt");

    string line;

    while (getline(spam_words, line))
    {
        words.push_back(line);
    }

    return words;
}

//Utility function for debugging
void print(vector<string> arr)
{
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
}

// Adding user specified spam words to stored database
void addSpamWords(string FileName, string Content)
{
    // transforms the word to lowercase for easier search operation
    transform(Content.begin(), Content.end(), Content.begin(), ::tolower);

    // Writing word to database
    ofstream spam_words;
    spam_words.open("Sources/" + FileName + ".txt", ios::app);
    spam_words << endl
               << Content;
    spam_words.close();
}

// Utility function to remove unessesary characters from words
string removeExtras(string word)
{
    // useless characters to remove from words
    vector<char> arr = {'.', ',', '!', '#', '&', '(', ')', '\'', '"', ':', ';',
                        '<', '>', '?', '/', '{', '}', '[', ']', '\\'};

    // string to store filtered word
    string filterdWord = "";

    for (int i = 0; i < word.length(); i++)
    {
        // flag insures only genuine characters are considered in current word
        bool flag = false;

        for (int j = 0; j < arr.size(); j++)
        {
            if (word[i] == arr[j])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            filterdWord.push_back(word[i]);
    }
    return filterdWord;
}

// Extract disinct words from given line
// Also, returns count of spam words in given line
pair<int, int> countSpamWords(string str)
{
    // total variable to store count of total words in given line
    int total = 0;

    // count variable to store count of spam words in given line
    int cnt = 0;

    // word variable to store word
    string word;

    // making a string stream
    stringstream iss(str);

    // Read and print each word.
    while (iss >> word)
    {
        word = removeExtras(word);
        total++;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (Spam.search(word))
            cnt++;
    }
    return {cnt, total};
}

// initialize the trie data structure
void initSpam()
{
    Spam.build(retrieve());
}

// main function to check spam words in given file
void spamChecker(string fileName)
{
    //Initialising data structures for checker to work
    initSpam();

    pair<long long, long long> totalSpams;

    ifstream file;
    file.open(fileName + ".txt");

    string line;

    while (getline(file, line))
    {
        pair<int, int> temp = countSpamWords(line);
        totalSpams.first += temp.first;
        totalSpams.second += temp.second;
    }

    cout << totalSpams.first << " out of " << totalSpams.second << " words" << endl;
}

int SpamFilter()
{
    int n;
    string word;
    cout << "Enter count of words to be entered : ";
    cin >> n;
    while (n--)
    {
        cin >> word;
        addSpamWords("SpamWords", word);
    }
    string name;
    cout << "Enter FileName of file to be check for spam : ";
    cin >> name;
    spamChecker(name);

    return 0;
}
int about()
{
    cout << "\n\nPlagiarism detection or content similarity detection is the process of locating instances of plagiarism andor copyright infringement within a work or document.\nThe widespread use of computers and the advent of the Internet have made it easier to plagiarize the work of others.\nDetection of plagiarism can be undertaken in a variety of ways. Human detection is the most traditional form of identifying plagiarism from written work. \nThis can be a lengthy and time-consuming task for the reader and can also result in inconsistencies in how plagiarism is identified within an organization. \nText-matching software (TMS), which is also referred to as plagiarism detection software or anti-plagiarism software, has become widely \navailable, in the form of both commercially available products as well as open-source[examples needed] software. TMS does not actually detect plagiarism per se, but instead finds \nspecific passages of text in one document that match text in another document";
    return 0;
}
int plagrism()
{
    int plag;
    cout << "1.Check plag\n";

    cout << "2.Add Original Data To Data base\n";
    cout << "3.Check Available File List\n";
    cout << "4.About Plagchecker\n";
    cout << "Enter your choice:-\t";
    cin >> plag;
    switch (plag)

    {
    case 1:
    {
        cout << "few";
        string filename1, topicname1;
        cout << "Enter topicname to check the plagrism:\t";
        cin >> topicname1;
        cout << "\n";
        cout << "Enter filename to check the plagrism:\t";
        cin >> filename1;
        Sleep(1000);
        loading();
        PlagChecker(topicname1, filename1);

        break;
    }
    case 2:
    {
        string filename2, content;
        cout << "Enter filename of this file into database:\t";
        cin >> filename2;
        cout << "Enter content of this file into database:\t";
        cin >> content;
        Sleep(1000);
        loading();
        AddSourceFile(filename2, content);
        cout << "many";
        break;
    }
    case 3:
    {
        cout << "List of content available:-\t";
        Sleep(1000);
        cout << "more";
        loading();
        SourceFileList();
        break;
    }
    case 4:

        cout << "What is plagchecker?";
        loading();
        about();
        break;
    default:
        cout << "Wrong choice";
    }
    return 0;
}
int headpage()
{
    int choice;
    cout << "1.Plagrism Checker\n";
    cout << "2.Spam Checker\n";
    cout << "Enter your choice:-\t";
    cin >> choice;
    switch (choice)
    {
    case 1:
        plagrism();
        break;
    case 2:
        cout << "abhijot";
        break;
    default:
        cout << "Wrong choice";
    }
    return 0;
}

int main()
{
    headpage();
    return 0;
}

// int main()
// {

//     cout << "Hie Death";
//     PlagChecker();

//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;
int SourceFileList();
int AddSourceFile(string, string);
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
                // cout << st1;

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

int main()
{

    cout << "Hie Death";
    PlagChecker();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<string> splitPath(const string &orgPath)
{
    vector<string> parts;
    stringstream ss(orgPath);
    string component;

    while (getline(ss, component, '/'))
    {
        parts.push_back(component);
    }

    return parts;
}

string simplifyPath(const string &orgPath)
{
    vector<string> pathStack;
    vector<string> parts = splitPath(orgPath);
    bool isAbsolutePath = !orgPath.empty() && orgPath[0] == '/';

    for (const string &component : parts)
    {
        if (component == "" || component == ".")
        {
            continue;
        }
        else if (component == "..")
        {
            if (!pathStack.empty())
            {
                pathStack.pop_back();
            }
            else if (!isAbsolutePath)
            {
                pathStack.push_back("..");
            }
        }
        else
        {
            pathStack.push_back(component);
        }
    }

    string resultPath;

    if (isAbsolutePath)
        resultPath = "/";
    else
        resultPath = "./";

    for (int i = 0; i < pathStack.size(); i++)
    {
        resultPath += pathStack[i];
        if (i != pathStack.size() - 1)
            resultPath += "/";
    }

    if (pathStack.empty())
    {
        return isAbsolutePath ? "/" : ".";
    }

    return resultPath;
}

int main()
{
    string inputPath;
    cin >> inputPath;

    string simplified = simplifyPath(inputPath);
    cout << simplified << endl;

    return 0;
}

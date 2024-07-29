#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string gimn, mer;
    cin>>gimn;
    cin>>mer;

    vector<int> array;
    int count=0;

    for (int i = 0; i <= gimn.length() - mer.size(); i++) {
        if (gimn[i]==mer[0])
        {
            int ind=0;
            while(gimn[i+ind]==mer[ind] and ind<mer.size())
            {
                ind++;
            }
            if (mer.size()==ind)
                {array.push_back(i);
                }
        }
    }

    cout << array.size() << endl;
    for (int i : array) {
        cout << i << " ";
    }

    return 0;
}


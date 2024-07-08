#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> A;
    
    
    int main = 1;
    while (main) 
    {
        cout << "*********MENU*********" << endl;
        cout << "1.Get data" << endl;
        cout << "2.Shell Sort" << endl;
        cout << "3.Display" << endl;
        cout << "4.Exit" << endl;
        int ch;
        cout<<"\n Enter your Choice:";
        cin >> ch;
        
        
        if (ch == 1) 
        {
            int n;
            cout << "Enter the Total Number of Element:";
            cin >> n;
            cout << "Enter the Element:" << endl;
            for (int i = 0; i < n; i++) 
            {
                int x;
                cin>>x;
                A.push_back(x);
            }
        }
        
        else if (ch == 2) 
        {
            int n = A.size();
            int gap = n / 2;
            while (gap > 0) 
            {
                for (int s = 0; s < n; s++) 
                {
                    for (int i = s + gap; i < n; i += gap) 
                    {
                        int minimum = A[i];
                        int j = i - gap;
                        while (j >= 0) 
                        {
                            if (A[j] <= minimum) 
                            {
                                break;
                            }
                            else 
                            {
                                A[j + gap] = A[j];
                                j = j - gap;
                            }
                        }
                        A[j + gap] = minimum;
                    }
                }
                for (int i = 0; i < n; i++) 
                {
                    cout << A[i] << " ";
                }
                cout << endl;
                gap = gap / 2;
            }
        }
        
        
        else if (ch == 3) 
        {
            int n = A.size();
            if (n == 0) 
            {
                cout << "Element is Empty" << endl;
            }
            else 
            {
                cout << "Element are:" << endl;
                for (int i = 0; i < n; i++) 
                {
                    cout << A[i] << " ";
                }
                cout << endl;
            }
        }
        else if (ch == 4) 
        {
            main = 0;
        }
        else 
        {
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}

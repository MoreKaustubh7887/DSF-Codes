/*Consider telephone book database of N clients. Make use of a hash table implementation to
quickly look up client‘s telephone number. Make use of two collision handling techniques and
compare them using number of comparisons required to find a set of telephone numbers*/


#include<iostream>
#include<vector>
using namespace std;

class Hash {
    private: int x;
    string tempname;
    public: int * hasharray; //storing the data
    string * namearray; //storing names
    int * link;
    int count;
    Hash(int s, string name1 = "user") {
        hasharray = new int[s];
        namearray = new string[s];
        link = new int[s];
        for (int i = 0; i < s; i++) {
            hasharray[i] = -1;
            namearray[i] = name1;
            link[i] = -1;
        }
    }
    void inserttable(int m, int s);
    void display(int s);
    void chainlink(int c, int m, int s, int removed);
    int position(int m, int hashfunctionvalue, int s, int flag);
    int hashfunction(int m, int s) {
        return m % s;
    }
};

void Hash::chainlink(int c, int m, int s, int removed) {
    int i = removed;

    while (i >= 0) {
        if (hasharray[i] % s == m % s and i != c and hasharray[i] != -1) {
            link[i] = c;
            break;
        }
        if (i == 0) {
            i = s;
        }
        i--;
    }

    if (i != c and hasharray[i] % s != m % s) {
        chainlink(i, m, s, i);
    }

    cout << "chainlink completed" << endl;
}

int Hash::position(int n, int hashfunctionvalue, int s, int flag = 0) {
    int t = hashfunctionvalue;
    int count = 1;
    int temp;
    int linkcount = 0;

    while (hasharray[t] != -1 and t <= s and count <= s) {
        if (hasharray[hashfunctionvalue] % s != hashfunctionvalue) {
            flag = 1;
            temp = hasharray[hashfunctionvalue];
            tempname = namearray[hashfunctionvalue];
            linkcount = position(temp, hashfunction(temp, s), s, flag);
            hasharray[hashfunctionvalue] = -1;

            chainlink(linkcount, temp, s, hashfunctionvalue);
            link[linkcount] = link[hashfunctionvalue];
            link[hashfunctionvalue] = -1;
            break;
        }
        if (t == s) {
            t = 0;
        } else {
            count++;
            t++;
        }
    }

    if (count == s + 1) {
        return -1;
    }
    if (flag == 1) {
        hasharray[t] = n;
        namearray[t] = tempname;

    }
    return t;
}

void Hash::inserttable(int m, int s) {
    int flag;
    int c;

    if (hasharray[hashfunction(m, s)] != -1) {
        cout << "\n\n------------COLLISION OCCURED------------\n1]change the existing\n2]linear probing with replaement \n3]linear probing without replacement \n ";
        cin >> flag;
        switch (flag) {

        case 1:
            hasharray[hashfunction(m, s)] = m;

            cout << "Enter name:------->";
            cin >> namearray[hashfunction(m, s)];
            break;
        case 2:
            c = position(m, hashfunction(m, s), s);
            if (c != -1) {

                hasharray[c] = m;

                cout << "Enter name:------->";
                cin >> namearray[c];
                if (c != hashfunction(m, s)) {
                    chainlink(c, m, s, c);
                }

            } else {
                cout << endl << "NO SPACE TO INSERT----> " << m << endl;
            }
            break;
        case 3:
            c = position(m, hashfunction(m, s), s);
            if (c != -1) {

                hasharray[c] = m;

                cout << "Enter name:------->";
                cin >> namearray[c];
                if (c != hashfunction(m, s)) {
                    chainlink(c, m, s, c);
                }

            } else {
                cout << endl << "NO SPACE TO INSERT----> " << m << endl;
            }
            break;
        }

    }

    if (hasharray[hashfunction(m, s)] == -1) {
        hasharray[hashfunction(m, s)] = m;
        cout << "Enter name:------->";
        cin >> namearray[hashfunction(m, s)];

    }

}

void Hash::display(int s) {
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    cout << "index   data   name   link\n";
    for (int i = 0; i < s; i++) {
        cout << i << " | " << hasharray[i] << " |" << namearray[i] << " |" << link[i] << "|" << endl;
    }
    cout << "------------------------------------------------------------------------------------------------------------------\n";
}

int main() {
    vector < Hash > hashtable;
    vector < int > size;
    int element;
    int choice;
    char choice1;
    int table = 0;
    do {

        cout << "------------------------ENTER YOUR CHOICE------------------------------- \n\n 1]MAKE TABLE\n 2]SHOW STORED HASH TABLES\n 3]DELETE TABLE \n choice------->";
        cin >> choice;
        cout << "------------------------------------------------------------------------\n";
        switch (choice) {
        case 1:
            table = size.size();
            cout << "\nMAKING table number " << table + 1 << "\nenter the size of the element------>";
            cin >> element;
            size.push_back(element);

            hashtable.push_back(size[table]);
            hashtable[table].display(size[table]);
            cout << "TABLE CREATED:---" << table + 1;
            do {

                cout << "\n-----------------------------------------------------------------\na)insert element\nb)display table\n";
                cout << "-------------------------------------------------------------------\n";
                cin >> choice1;
                switch (choice1) {
                case 'a':
                    cout << "Enter the element:------>";
                    cin >> element;
                    /*cout << "Enter name:------->";
                    cin >> hashtable[table].namearray[hashtable[table].hashfunction(element, size[table])];*/
                    hashtable[table].inserttable(element, size[table]);
                case 'b':
                    cout << "\n\nDISPLAYING THE TABLE\n\n";
                    hashtable[table].display(size[table]);
                    break;
                default:
                    cout << "wrong choice\n";
                };

                cout << "RETURN TO MENU (Y/N)\n";
                cin >> choice1;
            } while (choice1 == 'y' || choice1 == 'Y');

            cout << "table" << ++table << endl;
            break;

        case 2:

            cout << "------------------------------------------------------\n";
            cout << "DISPLAYING ALL THE TABLES";
            cout << "-------------------------------------------------------\n";
            while (table > 0) {
                cout << "TABLE NUMBER:-" << table << endl;
                table--;
                for (int i = 0; i < size[table]; i++) {
                    cout << i << " | " << hashtable[table].hasharray[i] << " |" << hashtable[table].namearray[i] << " |" << endl;
                }

            }
            break;
        case 3:
            cout << endl << "Enter the deletion table" << endl;
            cin >> choice;

            if (choice != 0) {
                delete[] hashtable[choice - 1].hasharray;
                delete[] hashtable[choice - 1].namearray;

                cout << " TABLE "<< choice <<" DELETED SUCCESSFULLY " << endl;
            } else {
                cout << "not exist" << endl;
            }

            break;

        default:
            cout << "WRONG CHOICE:\n";

        }
        cout << "RETURN TO MENUuuu (Y/N)\n";
        cin >> choice1;
    } while (choice1 == 'y' || choice1 == 'Y');
    cout << "\n\n\n[PROGRAM ENDED]\n\n\n";
    return 0;
}

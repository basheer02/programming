#include<iostream>
using namespace std;
template<class T>
class stack{
    protected :
        T top,n,s[];
    public :
        stack(T a){
            n = a;
            top = -1;
            for(int i=0;i<n;i++){
                s[i] = 0;
            }
        }

        bool stackFull(){
            if(top>=(n-1))
                return true;
            else
                return false;
        }
        bool stackEmpty(){
            if(top == -1)
                return true;
            else
                return false;
        }
        void push(T value){
            top++;
            s[top] = value;
            cout<<endl<<"  ";
            cout<<value;
            cout<<" pushed to stack top\n\n";
        }
        int pop(){
            int x;
            x = s[top];
            top--;
            cout<<"  stack top element ";
            cout<<x;
            cout<<" poped \n";
            return x;
        }
        void print(){
            if(stackEmpty())
                cout<<" stack is empty \n";
            else
            {
                cout<<"  elements in stack : ";
                for(int i=top;i>=0;i--){
                    cout<<s[i];
                    cout<<"  ";
                }
                cout<<endl<<endl;   
            }
        }
        
};
int main(){ 
    int t,ls,ch;
    cout<<" enter limit of stack : ";
    cin>>ls;
    stack <int> s(ls);
    do
    {
        cout<<" **************\n"<<endl;
        cout<<" Options  \n 1.push \n 2.pop \n 3.print \n 0.exit \n\n";
        cout<<" **************"<<endl<<endl;
        cout<<" Enter your option : ";
        cin>>ch;
        switch (ch)
        {
            case 0:
                return 0;
              //  break;  
            case 1:
                if(s.stackFull()){
                    cout<<" **************"<<endl;
                    cout<<" stack is full \n";
                }
                else{
                    cout<<" **************"<<endl;
                    cout<<"  Enter element : ";
                    cin>>t;
                    s.push(t);
                }
                break; 
            case 2:
                if(s.stackEmpty()){
                    cout<<" **************"<<endl;
                    cout<<" stack is empty \n";
                }
                else{
                    cout<<" **************"<<endl;
                    s.pop();
                }
                break;
            case 3:
                cout<<" **************"<<endl<<endl;
                s.print();
                break;
            default:
                return 0;
                //break;
        }
    } while (ch<4 && ch>=0);
    cout<<endl;
    return 0;
}                  
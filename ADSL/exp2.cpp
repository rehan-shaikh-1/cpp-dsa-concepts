        #include<iostream>
        #include<ios> //used to get stream size
        #include<limits> //used to get numeric limits
        #include <cstring>
        #include<stack>

        #define MAX 20
        using namespace std;
        //ADT Expression tree node
        class NODE{
            public:
            NODE *LC;//left child link
            char data;
            NODE *RC;//left child link	
        };
                
		bool isOperator(char token){
			return (token=='+' || token=='-' || token=='*' || token=='/' || token=='^');
		}
		
		bool isOperand(char token){
			return ((token>='a' &&  token<='z') || (token>='A' &&  token<='Z'));
		}

        void generateExpTree(char exp[], NODE* &root){
			stack<NODE*> S;
			NODE *p;
			
			for (int i=strlen(exp)-1;i>=0;i--){
				p=new NODE;
				p->LC=NULL;
				p->data=exp[i];
				p->RC=NULL;
				if(isOperand(exp[i]))
					S.push(p);
				else if (isOperator(exp[i])){
                p->LC = S.top(); S.pop();
                p->RC = S.top(); S.pop();
					S.push(p);	
				}
			}
			root=S.top(); S.pop();
		}

        void inOrder(NODE* root){
            if(root == NULL) return;
        inOrder(root->LC);
        cout << root->data << " ";
        inOrder(root->RC);
        }

        int main(){
            char exp[20];
            cout<<"\nEnter your expression";
            cin>>exp;

            NODE* root = NULL;

            generateExpTree(exp,root);
            inOrder(root);
        }
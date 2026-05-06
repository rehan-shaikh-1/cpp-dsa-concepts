        #include<iostream>
        #include<ios>
        #include<limits>
        #include <cstring>
        #include<stack>

        #define MAX 20
        using namespace std;
        class NODE{
            public:
            NODE *LC;
            char data;
            NODE *RC;	
        };
                
		bool isOperator(char token){
            return (token == '+' || token == '-' || token == '*' || token == '/');
		}
		
		bool isOperand(char token){
            return ((token >= 'a' && token <= 'z') || (token >= 'A' || token <= 'Z'));
		}

        void generateExpTree(char exp[], NODE* &root){
            stack <NODE*> S;
            NODE* p;


            for(int i = strlen(exp)-1;i>0;i++){
                p = new NODE;
                p->LC = NULL;
                p->data = exp[i];
                p->RC =NULL;
                if(isOperand(exp[i])){
                    S.push(p);
                }
                if(isOperator){
                    
                }
            }
		}

        void inOrder(NODE* root){
            if(root == NULL)   return;

            
        }

        int main(){
            char exp[20];
            cout<<"\nEnter your expression";
            cin>>exp;

            NODE* root = NULL;

            generateExpTree(exp,root);
            inOrder(root);
        }
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int x,y,a,b;
struct Node
{
    int x;
    int y;
    Node* next;
    Node* prev;
};
Node* head = NULL;
Node* tail = NULL;

void add_node(int a , int b){
        Node* temp = new Node;
        temp->next = head ;
        head = temp ;
}
void remove_first_node(){
            if(head==NULL)

              {cout << "null";
              }

            //moving the head pointer t the next node

            else{
            Node*temp = head ;
            head = head->next ;
            temp->next = NULL ;
            delete temp;

}
}



 int Del(int a, int b)
{
	if(head==NULL)return 0;

	if(head->x==a&&head->y==b)
	{
		struct Node* temp=head;
		head=temp->next;
		free(temp);
	}
	struct Node* temp=head->next;
	struct Node* prev=head;
	while(temp!=NULL)
	{
		if(temp->x==a&&temp->y==b)
		{
			prev->next=temp->next;
			free(temp);
			return 0;
		}
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)return -1;

}

void distance(float d)
{
	struct Node* temp=head;
	while(temp!=NULL)
	{
		int dist=(temp->x)*(temp->x)+(temp->y)*(temp->y);
		if(dist<=d*d){cout<<"("<<temp->x<<", "<<temp->y<<") ";}
		temp=temp->next;
	}
}
 bool Search(Node*head , int a , int b){

            Node* current = head;// initialize current

            while (current != NULL){

                if((current->x==a) && (current->y==b))
                    return true;
                current = current->next;
            }
            return false;
            }

int getcount(Node*head){

                    int count =0;//initialize count
                    Node*current = head ;//initialize current
                    while(current!=NULL){

                        count++;
                        current = current->next ;

                    }
                    return count ;

             }






int main()

{



     head = NULL;
        tail = NULL ;


        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

        long long z;

        cin >> z ;
        while(z--)

   {
             int q,a,b;
             cin>>q;

             if(q==1)
             {
                 cin>>a>>b;
                 add_node(a,b);
             }
        else if(q==2)
        {
           remove_first_node();
        }

        else if(q==3)
            {
              cin>>a>>b;
              Del(a,b);
            }
        else if(q==4)
            {
              float d;
              cin>>d;
              distance(d);
            }
        else if(q==5)
            {
                cin>> a >> b;
                if(Search(head,a,b)){
                    cout << "true";
                }
                else{
                    cout << "false";
                }
                cout << endl;
            }
        else if(q==6)
            {
              cout << getcount(head) << endl;
            }
   }

    return 0;
}

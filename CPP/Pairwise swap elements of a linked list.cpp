class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head)
    {
        // The task is to complete this method
        if(head==NULL || head->next == NULL)
            return head;
        
        Node* temp = head;
        head = head->next;
        
        while(temp && temp->next){
            Node* ptemp = temp;
            Node* ctemp = temp->next;
            temp = (temp->next)->next;
            
            ctemp->next = ptemp;
            if(temp && temp->next)
                ptemp->next = temp->next;
            else if(temp)
                ptemp->next = temp;
            else
                ptemp->next = NULL;
        }
        return head;
    }
};

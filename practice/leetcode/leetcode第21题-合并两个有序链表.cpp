struct ListNode* cur1=l1;
    struct ListNode* cur2=l2;
    struct ListNode* lis = NULL;
    struct ListNode* tail = NULL;

    while(cur1!=NULL||cur2!=NULL)
    {
        if(tail!=NULL)
        {
            if(cur1->val<=cur2->val)
             {
            tail->next=cur1;
            tail = cur1;
             }
            else{
                 tail->next=cur2;
                  tail = cur2;
            }
            cur1 = cur1->next;
        }
        else
        {
            if(cur1->val<=cur2->val)
            {
                lis = tail = cur1;
            }
            else
            {
            lis = tail =cur2;
            }
        }
    }
    if(cur1!=NULL)
    {
        tail->next = cur1;
    }
    else{
        tail ->next = cur2;
        }

    return lis;
}

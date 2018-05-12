#ifndef TWOSUM_LINKNODE_H
#define TWOSUM_LINKNODE_H
#include "stdio.h"
#include "cmath"

struct ListNode {
	    int val;
	    ListNode *next;
	    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p_1 = l1;
		ListNode* p_2 = l2;
		ListNode* l3;
// 		long long int num_1 = 0,num_2 = 0;
// 		long long int total = 0;		
// 		int index = 0;
// 		//compute num_1
// 		while(p_1!=NULL)
// 		{
// 			num_1 += int((p_1->val)*pow(10.0,index));
// 			p_1 = p_1->next;
// 			index++;
// 		}
// 		//compute num_2
// 		index = 0;
// 		while(p_2!=NULL)
// 		{
// 			num_2 += (long long int)((p_2->val)*pow(10.0,index));
// 			p_2 = p_2->next;
// 			index++;
// 		}
// 		 total = num_1+num_2;
// 
// 		l3 = new ListNode(total%10);
// 		total = total/10;
// 		ListNode* p = l3;
// 		while(total > 0)
// 		{
// 			ListNode* r;
// 			r = new ListNode(total%10);
// 			total = total/10;
// 			p->next = r;
// 			p = p->next;
// 		}	
		//将l1和l2加起来存到l3中
		l3 = new ListNode(p_1->val+p_2->val);
		p_1 = p_1->next;p_2 = p_2->next;
		ListNode* p_3 = l3;
		while(p_1!=nullptr||p_2!=nullptr)
		{
			ListNode* temp;
			if (p_1==nullptr)
			{
				temp = new ListNode(0+p_2->val);
				p_2 = p_2->next;
			}
			else if(p_2==nullptr)
			{
				temp = new ListNode(0+p_1->val);
				p_1 = p_1->next;
			}
			else
			{
				temp = new ListNode(p_1->val+p_2->val);
				p_1 = p_1->next;
				p_2 = p_2->next;
			}

			
			p_3->next = temp;


			p_3 = p_3->next;
		}
		//进位操作
		//除去头的一位的操作
		p_3 = l3;
		while(p_3->next!=NULL)
		{
			if (p_3->val>9)//如果大于9就进位
			{
				p_3->next->val += ((p_3->val)/10);
				p_3->val = (p_3->val)%10;
			}
			p_3 = p_3->next;
		}
		//对最后一个元素进行操作
		if (p_3->val>9)
		{
			ListNode* temp;
			temp = new ListNode((p_3->val)/10);
			p_3->val = (p_3->val)%10;
			p_3->next = temp;
		}
		 return l3;
	}
};

#endif

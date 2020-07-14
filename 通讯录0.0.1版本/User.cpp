#include"User.h"
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


void User::AddUser()
{
    UserNode* temp = Head;
    while (temp->next != NULL)   //�ҵ�����ĩβ
    {
        temp = temp->next;
    }
    temp ->next = new UserNode; 
    temp = temp->next;
    temp->Set_info();//��ӳ�ԱҪ¼����Ϣ
}

UserNode* User::SearchUser(IN_PARAM string first)
{
    UserNode* temp = Head;
    if (temp->next == NULL)return NULL;
    temp = temp->next;//�ӵڶ����ڵ㿪ʼ����
    while(temp != NULL)
    {
        if(first == temp->str_name)
        {
            return temp;
        }
        if (first == temp->str_phone_num)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//arch���������del��revise����
void User::DeleteUserNode(IN_PARAM string first) //ɾ���û�
{
    if(NULL == (Head->next))
    {
        cout << "ͨѶ¼Ϊ��" << endl;
        return;
    }
    UserNode* temp = SearchUser(first);
    if(temp == NULL)
    {
        cout << "���޴���" <<endl;
        return;
    }
             UserNode* ptr = Head;
            while(ptr->next != temp)
            {
                ptr = ptr->next;
            }
            ptr->next = temp->next;
            delete temp;
}

void User::Main_view()
{
    cout << " | ***********��ӭ����ͨѶ¼����ϵͳ*************|" << endl;
    cout << " | ----------------------------------------------|" << endl;
    cout << " | ************----����ģʽ----******************|" << endl;
    cout << " | ----------------------------------------------|" << endl;
    cout << " | *********  (�����Ӧ��Ž�����Ӧģ��)  *******|" << endl;
    cout << " | 1����¼����Ϣ            2������ʾȫ����Ϣ    |" << endl;
    cout << " | ----------------------------------------------|" << endl;
    cout << " | 3��������ͨѶ¼��Ϣ      4����ɾ����Ϣ        |" << endl;
    cout << " | ----------------------------------------------|" << endl;
    cout << " | 5�����޸���Ϣ            5����չʾ�Ǳ�        |" << endl;
    cout << " | ----------------------------------------------|" << endl;
    cout << " | 6����չʾ����            7����������Ϣ        |" << endl;
    cout << " | ----------------------------------------------|" << endl;
    cout << " | 8������ȡ��Ϣ          ��0�˳�                |" << endl;
    cout << " | ----------------------------------------------|" << endl;
}

void User::Display()
{

    int n, key = 0, lab = 0;	//key�����˳���lab��������
    for (;;) {
        if (lab == 0) {
            system("cls");		    //����
            Main_view();		//���´�ӡ�˵�
        }
        cin >> n;
        getchar(); //�Ե��س�
        string first;
        switch (n)
        {
        case 1:
            AddUser();
            lab = 0;
            break;
        case 2:	//��ʾ��Ϣ
            //Show();
            lab = 0;
            break;
        case 3:	//����
            cout << "���������Ϣ�����ֻ��ߵ绰��" << endl;
               
              cin >> first;
            SearchUser(first);
            lab = 0;
            break;
        case 4:	 //ɾ��
            cout << "����ɾ������Ϣ�����ֻ��ߵ绰��" << endl;
            
            cin >> first;
            DeleteUserNode(first);
            lab = 0;

            break;
        case 5:	//  �޸�
            cout << "�����޸ĵ���Ϣ�����ֻ��ߵ绰��" << endl;

            cin >> first;
            ReviseUser(first);
            lab = 0;
            break;
        case 6:	//  ����
            lab = 0;
            break;
        case 7:	//  ����
            lab = 0;
            break;
        case 8://��ȡ
            lab = 0;
            break;

        case 0:
            key++;
            lab = 0;
            break;
        default:
            cout << "����������������" << endl;
            lab++;
            break;
        }
        if (key != 0)
            break;//��0�˳�
    }
}

void User::ReviseUser(IN_PARAM string first) { //�޸��û�
    if (NULL == (Head->next))
    {
        cout << "ͨѶ¼Ϊ��" << endl;
        return;
    }
    UserNode* temp = SearchUser(first);
    if (temp == NULL)
    {
        cout << "���޴���" << endl;
        return;
    }

    /*�޸���Ϣ*/

}

UserNode::UserNode()
{
    next = NULL;
    b_is_classmate = false;
    b_is_colleague = false;
    b_is_important = false;
    b_is_relative = false;
    b_is_printed = false;

}

void UserNode::Set_info()
{
}

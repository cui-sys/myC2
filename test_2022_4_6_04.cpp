#include <iostream>

using namespace std;
//����Ͷ���
#if 0
//C ���Ե�˼�룺���ݺͷ����Ƿֿ���
//����
typedef struct
{
    char name [32];
    int age;
}Person;//��
typedef struct
{
    char name[32];
    int age;
    int type;
}Animal;//����
//����
void PersonEat(Person* p)
{
    cout<<p->name<<"���ڳԷ�"<<endl;
}
void AnimalEat(Animal* p)
{
    cout<<p->name<<"���ڳԹ���"<<endl;
}
void test()
{
    Person person = { "����", 43 };
    Animal dog = { "����", 3 };

    PersonEat(&person);
    AnimalEat(&dog);

    //���ݺͷ�������������ɷ������ô�������
    AnimalEat((Animal*)&person);
}
#endif
//����װ��- �ѱ��������ԣ��ͺ������������ϳ�һ�����壬��װ��һ������
//�Ա����ͺ������з��ʿ��ƣ����У���˽�У���������
//������ڲ���������Χ�ڣ���û�з���Ȩ��֮�֣����г�Ա�����໥����
//������ⲿ��������Χ�⣩������Ȩ�޲������壺public(����), private(˽��), protected(����)
//������ⲿ,ֻ�� public ���εĳ�Ա���ܱ����ʣ���û���漰�̳�������ʱ��private �� protected ��ͬ�ȼ��ģ��ⲿ��������ʡ�
//����ĳ�ʶ�� -
/*
            class ���� {//����ĸ��� ϵͳ����Ϊ�����ռ�
                private://˽�� ����ⲿ����ֱ�ӷ���
                protected://����
                ����
                public://���� ����ⲿ����ֱ�ӷ���
                ����


                //������ڲ�û��Ȩ��֮�� �����໥����
            };
*/
class  Person{
private:
    int m_money;//˽������
protected:
    int m_age;//��������
public://��������
    void dese()
    {
        m_money = 100;//������ڲ�û��Ȩ��֮�� �����໥����
        m_age = 23;
        cout<<"�Nɪ!"<< " ����" << m_age<< " Ǯ��" << m_money <<endl;
    }
};

void test()
{
    //���� ȥ ʵ���� һ������(������ Person ����һ������)
    Person lucy;
    //lucy.m_money = 200;// err ˽������ ����ⲿ���ɷ���
    //cout <<"�������"<<lucy.m_age<<endl;// err �������� ����ⲿ���ɷ���

    lucy.dese();// ok �������� ���Է���
    // pricate, protected ��Ȼ�з���Ȩ�� ���ⲻ�ɷ��ʣ����ǿ��Խ��� public ���еķ��� ��ӵķ��� ˽�С����� �����ݡ�
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

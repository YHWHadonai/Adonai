#include<stdio.h>
#include<stdlib.h>
typedef struct PolyNode *Polynomial;  //定义链表
struct PolyNode{
    int coef;
    int expon;
    Polynomial link;
};                 //定义链表

    /*定义函数*/
    Polynomial ReadPoly();
    Polynomial Mult(Polynomial P1,Polynomial P2);
    void PrintfPoly(Polynomial PP);
    Polynomial Add(Polynomial P1,Polynomial P2);
    void Attach(int c,int e,Polynomial *pRear);
    /*       */


int main()
{   
    Polynomial P1,P2,PP,PS;

    P1=ReadPoly();  //读入多项式一
    P2=ReadPoly();  //读入多项式二
    PP=Mult(P1,P2); //使P1,P2相乘
    PrintfPoly(PP);  //输出相乘后的结果
    PS=Add(P1,P2);  //使P1,P2相加
    PrintfPoly(PS);  //输出相加后结果

    return 0;
}
Polynomial ReadPoly()
{
    void Attach(int c,int e,Polynomial *pRear);
    int n,c,e;
    scanf("%d",&n); // 读入多项式个数
    Polynomial P,Rear,t; //定义链表P，末结点Rear；
    P=(Polynomial)malloc(sizeof(struct PolyNode)); //为链表头结点申请空间
    P->link=NULL; //  先理解它是初始化,不定义下一个结点的话，为未知。
    Rear=P;
    while(n--){
        scanf("%d %d",&c,&e); //输入c为系数，e为指数
        Attach(c,e,&Rear); //将c，e插入到链表P的尾部
    }
    t = P;P=P->link;free(t);//删除空的头结点
    return P;  //返回链表P
}
void Attach(int c,int e,Polynomial *pRear)
{
    Polynomial P;

    P=(Polynomial)malloc(sizeof(struct PolyNode)); //申请空间
    P->coef=c;  //将系数c输入P中
    P->expon=e; //将指数e输入P中
    P->link=NULL; //先理解它是初始化
    (*pRear)->link=P; //将P插入到Rear后面
    *pRear=P; //使Rear为P，即让Rear后移一位
}
Polynomial Add(Polynomial P1,Polynomial P2)
{
    int sum;
    Polynomial t1,t2,P,Rear,temp;//定义结点
    t1=P1;t2=P2;
    P=(Polynomial)malloc(sizeof(struct PolyNode)); //申请空间
    P->link=NULL;       //初始化

    Rear=P;
    while(t1 && t2){
        if(t1->expon == t2->expon){        //比较两行列式指数的大小
            sum =  t1->coef + t2->coef;        //若相等，则系数相加，指数读入
            if(sum)Attach(sum,t1->expon,&Rear);//判断相加结果是否为0，若为0，则不读入
            t1=t1->link;t2=t2->link;  //双方结点后移一位
        }
        else if(t1->expon > t2->expon){  //若t1大
            Attach(t1->coef,t1->expon,&Rear);//读入t1的系数与指数
            t1=t1->link;  //t1结点后移
        }
        else{
            Attach(t2->coef,t2->expon,&Rear);//若t2大，读入t2的系数与指数
            t2=t2->link; //t2结点后移
        }
    }
    while(t1) {
        Attach(t1->coef,t1->expon,&Rear); //若t1还有数，直接插入链表
        t1=t1->link;
    }
    while(t2){
        Attach(t2->coef,t2->expon,&Rear);//若t2还有数，直接插入链表
        t2=t2->link;
    }
    temp=P;   //清除空的头结点
    P=P->link;//并使Rear指向有数值的后一位结点
    free(temp);   //释放头结点空间

    return P;  //返回相加后的链表头结点
}
Polynomial Mult(Polynomial P1,Polynomial P2)
{
    Polynomial P,Rear,t1,t2,t;
    int c,e;
    if(!P1 || !P2) return NULL;    //有任一链表为空，则结果为空

    t1=P1;t2=P2;  
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    Rear = P;  
    while(t2) //将t1的第一项乘t2，生成一个新链表
    {
        Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
        t2=t2->link;
    }
    t1=t1->link;
    while(t1)
    {
         t2=P2;Rear=P;
         while(t2)
        {
            c=t1->coef*t2->coef;
            e=t1->expon+t2->expon;
            while(Rear->link && Rear->link->expon>e) //从高向低，依次寻找
                Rear=Rear->link;
            if(Rear->link && Rear->link->expon==e) //若指数相等，则系数相加
            {
                if(Rear->link->coef+c) //系数相加不为0
                    Rear->link->coef+=c;
                else    //系数相加为0
                {
                    t=Rear->link;       //删除该结点
                    Rear->link=t->link;
                    free(t);
                }    
            }
            else //若指数不相等，插入结点
            {
                t=(Polynomial)malloc((sizeof(struct PolyNode)));
                t->coef=c;
                t->expon=e;
                t->link=Rear->link;
                Rear->link=t;
                Rear=Rear->link;
            }
            t2=t2->link;
        }
         t1=t1->link;
    }
    t=P;
    P=P->link;
    free(t);    //释放头空结点的储存空间
    return P;
}
void PrintfPoly(Polynomial PP)
{
     
    int flag=0;
    if(!PP) printf("0 0");
    while(PP){
        if(!flag) flag=1;
        else printf(" ");
        printf("%d %d",PP->coef,PP->expon);
        PP=PP->link;
    }
    printf("\n");
}
#include<stdio.h>
struct sjf { //定义进程的结构体
    char name[10];//进程名
    float arrivetime;//到达时间
    float servicetime;//服务时间
    float starttime;//开始时间
    float finishtime;//完成时间
    float zztime; //周转时间
    float dqzztime;//带权周转时间

};
struct sjf b[100];
//定义短作业优先算法进程的最大数量
void Sinput(struct sjf *p,int N) { //输入函数
    int i;
    printf("输入进程的名称、到达时间、服务时间:（例如   : x 0 100)\n");
    for(i=0; i<=N-1; i++) {
        printf("输入第%d进程的名称、到达时间、服务时间:",i+1);
        scanf("%s%f%f",&p[i].name,&p[i].arrivetime,&p[i].servicetime);

    }

}

//输出函数
void SPrint( struct sjf *p,float arrivetime,float servicetime,
             float starttime,float finishtime,float zztime,float dqzztime,int N) 
{
    int k;
    printf("\n执行顺序:\n");
    printf("%s",p[0].name);
    for(k=1; k<N; k++) {
        printf("-%s",p[k].name);
    }
    printf("\n进程名\tarrive\tservice\tstart\tfinish\tzhouzhuan\tdaiquanzz\n");
    for(k=0; k<=N-1; k++) {
        printf("%s\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t\n\n",
        p[k].name,p[k].arrivetime,p[k].servicetime,p[k].starttime,p[k].finishtime,
        p[k].zztime,p[k].dqzztime);


    }
    printf("\n");

    } 
    void Ssort(struct sjf *p,int N) 
    { //按短作业优先算法排序
        int i,j;
        for( i=1; i<=N-1; i++)
            for( j=1; j<=i; j++)
                if(p[i].servicetime<p[j].servicetime) {
                    struct sjf temp;
                    temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;

                }
    }
//运行结果
    void Sdeal(struct sjf *p,float arrivetime,float servicetime,
    float starttime,float finishtime,float zztime,float dqzztime,int N)

    {
        int k;
        for(k=0; k<=N-1; k++) {
            if(k==0) {
                p[k].starttime=p[k].arrivetime;
                p[k].finishtime=p[k].arrivetime+p[k].servicetime;
            } else {
                p[k].starttime=p[k-1].finishtime;
                //开始时间 =    前一个进程的完成时间
                p[k].finishtime=p[k-1].finishtime+p[k].servicetime;
                //结束时间=前一个进程的完成时间  + 现在进程的服务时间


            }

        }



    for(k=0; k<=N-1; k++) {
        p[k].zztime=p[k].finishtime-p[k].arrivetime;
        //  周转时间 =完成时间 -到达时间
        p[k].dqzztime=p[k].zztime/p[k].servicetime;
        //带权周转时间=周转时间 /服务时间

    }

}

void SJF(struct sjf *p,int N)

{
    float arrivetime=0,servicetime=0,starttime=0,
    finishtime=0,zztime=0,dqzztime=0;
    Ssort(p,N);
    Sdeal(p,arrivetime,servicetime,starttime,finishtime,zztime,dqzztime,N);
    SPrint(p,arrivetime,servicetime,starttime,finishtime,zztime,dqzztime,N);
}

void main() { //主函数

    int M;
    printf("-----------短作业优先调度算法-----------\n");
    printf("输入进程数:");
    scanf("%d",&M);
    Sinput(b,M);
    SJF(b,M);

}


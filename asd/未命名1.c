#include<stdio.h>
struct sjf { //������̵Ľṹ��
    char name[10];//������
    float arrivetime;//����ʱ��
    float servicetime;//����ʱ��
    float starttime;//��ʼʱ��
    float finishtime;//���ʱ��
    float zztime; //��תʱ��
    float dqzztime;//��Ȩ��תʱ��

};
struct sjf b[100];
//�������ҵ�����㷨���̵��������
void Sinput(struct sjf *p,int N) { //���뺯��
    int i;
    printf("������̵����ơ�����ʱ�䡢����ʱ��:������   : x 0 100)\n");
    for(i=0; i<=N-1; i++) {
        printf("�����%d���̵����ơ�����ʱ�䡢����ʱ��:",i+1);
        scanf("%s%f%f",&p[i].name,&p[i].arrivetime,&p[i].servicetime);

    }

}

//�������
void SPrint( struct sjf *p,float arrivetime,float servicetime,
             float starttime,float finishtime,float zztime,float dqzztime,int N) 
{
    int k;
    printf("\nִ��˳��:\n");
    printf("%s",p[0].name);
    for(k=1; k<N; k++) {
        printf("-%s",p[k].name);
    }
    printf("\n������\tarrive\tservice\tstart\tfinish\tzhouzhuan\tdaiquanzz\n");
    for(k=0; k<=N-1; k++) {
        printf("%s\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t\n\n",
        p[k].name,p[k].arrivetime,p[k].servicetime,p[k].starttime,p[k].finishtime,
        p[k].zztime,p[k].dqzztime);


    }
    printf("\n");

    } 
    void Ssort(struct sjf *p,int N) 
    { //������ҵ�����㷨����
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
//���н��
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
                //��ʼʱ�� =    ǰһ�����̵����ʱ��
                p[k].finishtime=p[k-1].finishtime+p[k].servicetime;
                //����ʱ��=ǰһ�����̵����ʱ��  + ���ڽ��̵ķ���ʱ��


            }

        }



    for(k=0; k<=N-1; k++) {
        p[k].zztime=p[k].finishtime-p[k].arrivetime;
        //  ��תʱ�� =���ʱ�� -����ʱ��
        p[k].dqzztime=p[k].zztime/p[k].servicetime;
        //��Ȩ��תʱ��=��תʱ�� /����ʱ��

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

void main() { //������

    int M;
    printf("-----------����ҵ���ȵ����㷨-----------\n");
    printf("���������:");
    scanf("%d",&M);
    Sinput(b,M);
    SJF(b,M);

}


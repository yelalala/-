#include<iostream>
#include<string.h>
#include<windows.h>
#include<time.h>
using namespace std;


#define true 1
#define false 0
#pragma once

typedef int Rank;


bool bubble(int array1[], int n) {
    int i = 0;
    bool sorted = true;//���������־
    while (++i < n)//�������ң���һ����������Ԫ��
        if (array1[i - 1] > array1[i]) {//����������ζ����δ�������򣬲���Ҫͨ������ʹ�ֲ�����
            sorted = false;
            swap(array1[i - 1], array1[i]);
        }
    return sorted;//���������־
} //ɨ�轻��

void bubbleSort(int array[], int n) {
    while (!bubble(array, n--));
} //���������㷨



void merge(int array[],int lo, int mi, int hi) { // lo < mi < hi
    int* A = array + lo; //�ϲ������������A[0, hi - lo) = _elem[lo, hi)
    int lb = mi - lo; int* B = new int[lb]; //ǰ������B[0, lb) <-- _elem[lo, mi)
    for (Rank i = 0; i < lb; B[i] = A[i++]); //����ǰ������
    int lc = hi - mi; int* C = array + mi; //��������C[0, lc) = _elem[mi, hi)
    for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);) {//B[j]��C[k]�е�С������Aĩβ
        if ((j < lb) && (!(k < lc) || (B[j] <= C[k]))) {
            A[i++] = B[j++];
        }
        if ((k < lc) && (!(j < lb) || (C[k] < B[j]))) {
            A[i++] = C[k++];
        }
    }
    delete[] B; //�ͷ���ʱ�ռ�
} //�鲢�㷨

void mergeSort(int array[],int lo,int hi) {
    if (hi-lo < 2) return; //��Ԫ��������Ȼ���򣬷���...
    int mi = (lo + hi) / 2; //���е�Ϊ��
    mergeSort(array,lo, mi); mergeSort(array,mi, hi); //ǰ׺����׺�ֱ�����
    merge(array,lo, mi, hi); //�鲢
} //�鲢�����㷨


void insertionSort(int array[], int n) {//��������
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = array[i];
		j = i - 1;

		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}

void selectionSort(int array[], int n) {//ѡ������
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (array[j] < array[min_idx])
				min_idx = j;
		swap(array[min_idx], array[i]);
	}
}

void quickSort(int array[], int lo, int hi) {//��������
	if (lo < hi) {
		int pivot = array[hi];
		int i = lo - 1;
		for (int j = lo; j <= hi - 1; j++) {
			if (array[j] < pivot) {
				i++;
				swap(array[i], array[j]);
			}
		}
		swap(array[i + 1], array[hi]);
		int pi = i + 1;
		quickSort(array, lo, pi - 1);
		quickSort(array, pi + 1, hi);
	}
}

int main()
{
    srand(time(0));//�������������ʱ����أ�ȷ����������ȫ����ĸ���
    double time = 0;
    double counts = 0;
    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    int nn1[10],nn2[10],nn3[10],nn4[10],nn5[10];//�������һ����
	
    for (int i = 0; i < 10; i++) {
        nn1[i] = rand() % 100;
        nn2[i] = nn1[i];
		nn3[i] = nn2[i];
		nn4[i] = nn2[i];
		nn5[i] = nn2[i];
    }//��ֵ

	cout << "����:";
	for (int i = 0; i < 10; i++) {
		cout << nn1[i] << " ";
	}


	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	mergeSort(nn1,0, 10);//����ʱ�鲢����
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout <<endl<< "����ʱ�鲢��������ʱ�䣺" << time * 1000 << "ms" << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	bubbleSort(nn2, 10);//����ʱ��������
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "����ʱ������������ʱ�䣺" << time * 1000 << "ms" << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	insertionSort(nn3, 10);//����ʱ��������
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout <<"����ʱ������������ʱ�䣺" << time * 1000 << "ms" << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	selectionSort(nn4, 10);//����ʱѡ������
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "����ʱѡ����������ʱ�䣺" << time * 1000 << "ms" << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	quickSort(nn5,0,10);//����ʱ��������
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "����ʱ������������ʱ�䣺" << time * 1000 << "ms" << endl << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	mergeSort(nn1,0, 10);//˳��ʱ�鲢����
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "˳��ʱ�鲢��������ʱ�䣺" << time * 1000 << "ms" << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	bubbleSort(nn2, 10); //˳��ʱ��������
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "˳��ʱ������������ʱ�䣺" << time * 1000 << "ms" << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	insertionSort(nn3, 10); //˳��ʱ��������
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "˳��ʱ������������ʱ�䣺" << time * 1000 << "ms" << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	selectionSort(nn4, 10);//˳��ʱѡ������
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "˳��ʱѡ����������ʱ�䣺" << time * 1000 << "ms" << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	quickSort(nn5,0,10);//˳��ʱ��������
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "˳��ʱ������������ʱ�䣺" << time * 1000 << "ms" << endl << endl;

	for (int i = 0; i < 5; i++) {
		swap(nn1[i], nn1[9 - i]);
		swap(nn2[i], nn2[9 - i]);
		swap(nn3[i], nn3[9 - i]);
		swap(nn4[i], nn4[9 - i]);
		swap(nn5[i], nn5[9 - i]);
	}//����������

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	mergeSort(nn1,0, 10);//����ʱ�鲢����
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "����ʱ�鲢��������ʱ�䣺" << time * 1000 << "ms" << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	bubbleSort(nn2, 10);//����ʱ��������
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "����ʱ������������ʱ�䣺" << time * 1000 << "ms" << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	insertionSort(nn3, 10);//����ʱ��������
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "����ʱ������������ʱ�䣺" << time * 1000 << "ms" << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	selectionSort(nn4, 10);//����ʱѡ������
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "����ʱѡ����������ʱ�䣺" << time * 1000 << "ms" << endl;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ  
	quickSort(nn5,0, 10);//����ʱ��������
	QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	cout << "����ʱ������������ʱ�䣺" << time * 1000 << "ms" << endl;
}

#pragma once
#include<iostream>
#ifndef QUEUE_H
#define QUEUE_H

#define NULL 0
using namespace std;
#define Elemtype1 int//µãkey
#define True  1
#define False 0
#define Ok    1
#define Error 0
#define Infeasible -1
#define Overflow   -2
typedef int Status;

class QueueNode{
public:
	Elemtype1 v;
	QueueNode * next;
	QueueNode(Elemtype1 v1){
		v = v1;
		next = NULL;
	}
	QueueNode(){

	}
};
class Queue{
	QueueNode *last;
	QueueNode *base;
	
public:
	
	int length;
	Queue(){
		length = 0;
		base = NULL;
		last = NULL;
	}
	Status push(Elemtype1 v1){
		QueueNode* node=new QueueNode(v1);
		if (base == NULL){
			base = node;
			last = node;
		}
		else{
			//cout << base->v << endl;
			last->next = node;
			last = node;
		}
		length++;
		return Ok;
	}
	Elemtype1 back(){
	
		if (base != NULL){
			Elemtype1 v = base->v;
			if (base->next == NULL){
				base = NULL;
			}
			else{
				base = base->next;
			}
			length--;
			return v;
			
		}
		else{
			return Error;
		}
		
	}
	Status show(){
		QueueNode *work=base;
		while (work != NULL){

			cout << work->v<<endl;
			//cout << work->next << endl;
			work = work->next;
		}
		return Ok;
	}
};

#endif
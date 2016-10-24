#ifndef TREENODE
#define TREENODE
#include <iostream>
#include <string.h>
using namespace std;
struct inf {
    inf():Name("-"),Fam("-"),Grp("-"){
    }
    inf(inf *i):Name(i->Name),Fam(i->Fam),Grp(i->Grp){}
    string Name;
    string Fam;
    string Grp;
};
#define MAXWORD 100
struct tnode {                // узел дерева
  inf *pers;
  int count;                   // число вхождений
  struct tnode *left;          // левый потомок
  struct tnode *right;         // правый потомок
};
// Функция добавления узла к дереву
struct tnode *addtree(struct tnode *p, inf *pers) {
  int cond;
  if(p == NULL) {
    p = (struct tnode *)malloc(sizeof(struct tnode));
    p->pers = new inf(pers);/*cout<<"k";*/
    p->count = 1;
    p->left = p->right = NULL;
  } else if((cond = strcmp(pers->Fam.c_str(),p->pers->Fam.c_str())) == 0)
  {p->count++;cout<<" count"<<pers->Fam<<" "<<p->pers->Fam;}
  else if(cond < 0){
      p->left = addtree(p->left, pers);/*cout<<"l";*/
  }else{
      p->right = addtree(p->right, pers);/*cout<<"r";*/
  }
  return p;
}
// Функция удаления поддерева
void freemem(tnode *tree) {
  if(tree!=NULL) {
      freemem(tree->left);
      freemem(tree->right);
      free(tree);
    }
}
// Функция вывода дерева
void treeprint(struct tnode *p) {
  if(p != NULL) {
    treeprint(p->left);
    printf("%d %s\n", p->count, p->pers->Fam.c_str());
    treeprint(p->right);
  }
}
//При этом обход дерева в префиксной форме будет иметь вид
void treeprint_PREFIX(tnode *tree) {
  if (tree!=NULL) { //Пока не встретится пустой узел
    cout<<"count: "<<tree->count <<" Fam: " << tree->pers->Fam<<" Name: " << tree->pers->Name<<" Grp: " << tree->pers->Grp<<endl; //Отображаем корень дерева
    treeprint_PREFIX(tree->left); //Рекурсивная функция для левого поддерева
    treeprint_PREFIX(tree->right); //Рекурсивная функция для правого поддерева
  }
}
//Обход дерева в инфиксной форме будет иметь вид
void treeprint_INFIX(tnode *tree) {
  if (tree!=NULL) { //Пока не встретится пустой узел
    treeprint_INFIX(tree->left); //Рекурсивная функция для левого поддерева
    cout<<"count: "<<tree->count <<" Fam: " << tree->pers->Fam<<" Name: " << tree->pers->Name<<" Grp: " << tree->pers->Grp<<endl; //Отображаем корень дерева
    treeprint_INFIX(tree->right); //Рекурсивная функция для правого поддерева
  }
}
//Обход дерева в постфиксной форме будет иметь вид
void treeprint_POSTFIX(tnode *tree) {

  if (tree!=NULL) { //Пока не встретится пустой узел
    treeprint_POSTFIX(tree->left); //Рекурсивная функция для левого поддерева
    treeprint_POSTFIX(tree->right); //Рекурсивная функция для правого поддерева
    cout<<"count: "<<tree->count <<" Fam: " << tree->pers->Fam<<" Name: " << tree->pers->Name<<" Grp: " << tree->pers->Grp<<endl; //Отображаем корень дерева
  }
}

tnode* find(tnode *r, char* d)
{
    int cond = strcmp(d, r->pers->Fam.c_str());
if (r==NULL)
   {
   return NULL;  // не найден
   }
if(cond == 0)
   {
   return r; // нашли!!!
   }

if (cond<=0)
  {
  // left
  if (r->left!=NULL)
    return find(r->left,d); // рекурсивный поиск влево
  else
     {
     return NULL; // не найден
     }
  }
else
  {
  //right
  if (r->right)
    return find(r->right,d);// рекурсивный поиск вправо
  else
    {
    return NULL; // не найден
    }
  }
}

#endif // TREENODE


#include <iostream>
#include <array>
using namespace std;
template <class t>

class Array
{
private:
  int length, size;
  t *arr;

public:
  Array(int s)
  {
    size = s;
    arr = new t[size];
    length = 0;
  }

  // IsEmpty
  bool isEmpty()
  {
    return (length == 0);
  }

  // is full
  bool isFull()
  {
    return (length == size);
  }

  // Add or append
  void add(t item)
  {
    if (!isFull())
    {
      arr[length] = item;
      length++;
    }
    else
    {
      cout << "array is full\n";
    }
  }

  // fill
  void Fill()
  {
    int no_of_items;
    cout << "How many items you want fill \n";
    cin >> no_of_items;
    if (no_of_items > size)
    {
      cout << "please enter items less of array size \n";
    }
    else if (no_of_items <= size)
    {
      for (int i = 0; i < no_of_items; i++)
      {
        cout << "enter the item no " << i + 1 << "\n";
        cin >> arr[i];
        length++;
      }
    }
  }

  // insert
  void insert(int index, t item)
  {
    if (index >= size || index < 0)
      return;

    if (!isFull())
    {
      for (int i = length; i > index; i--)
      {
        arr[i] = arr[i - 1];
      }
      arr[index] = item;
      length++;
    }
    else
      cout << "full array\n";
  }

  // delete
  t Delete(int index)
  {

    if (!isEmpty())
    {
      if (index >= 0 && index <= length)
      {
        t temp = arr[index];
        for (int i = index; i < length - 1; i++)
        {
          arr[i] = arr[i + 1];
        }
        length--;
      }
    }
    else
      cout << "empty array\n";
  }

  // display
  void display()
  {
    if (!isEmpty())
    {
      cout << "[ ";
      for (int i = 0; i < length; i++)
      {
        cout << arr[i] << " ";
      }
      cout << " ]\n";
    }
    else
      cout << "empty array\n";
  }

  // search
  int search(t item)
  {
    int index = -1;
    if (!isEmpty())
    {
      for (int i = 0; i < length; i++)
      {
        if (item == arr[i])
        {
          index = i;
          break;
        }
      }
    }
    return index;
  }

  // getsize
  int getSize()
  {
    return size;
  }

  // get length
  int getLength()
  {
    return length;
  }

  // reverse
  t reverse()
  {
    t rev[size];
    if (!isEmpty())
    {
      for (int i = 0; i < length; i++)
      {
        rev[i] = arr[size - i - 1];
      }
    }
    return rev;
  }

  // Elarge
  void elarge(int newsize)
  {
    t *old = arr;
    if (newsize > size)
    {
      size = newsize;
      arr = new t[size];
      for (int i = 0; i < length; i++)
      {
        arr[i] = old[i];
      }
      delete old;
    }
    else
      cout << "size must be larger than old size\n";
  }
};
class Node
{
public:
  int data;
  Node *next;
};
class Linkedlist
{
private:
  Node *head;
  int length;

public:
  Linkedlist()
  {
    head = NULL;
    length = 0;
  }

  // isempty
  bool isEmpty()
  {
    return (head == NULL);
  }

  // insert first
  void insertFirst(int item)
  {
    Node *newnode = new Node();
    newnode->data = item;
    if (isEmpty())
    {
      newnode->next = NULL;
      head = newnode;
    }
    else
    {
      newnode->next = head;
      head = newnode;
    }
    length++;
  }

  // insert before item
  void insertBefore(int prvitem, int newitem)
  {
    if (isEmpty() || head->data == prvitem)
      insertFirst(newitem);

    if (isFound(prvitem))
    {
      Node *temp = head;
      while (temp != NULL && temp->next->data != prvitem)
      {
        temp = temp->next;
      }
      Node *newnode = new Node();
      newnode->data = newitem;
      newnode->next = temp->next;
      temp->next = newnode;
    }
  }

  // insert after item
  void insertAfter(int item, int newitem)
  {
    if (isEmpty())
      insertFirst(newitem);

    if (head->data == item)
    {
      Node *temp = head;
      Node *newnode = new Node();
      newnode->data = newitem;
      newnode->next = temp->next;
      temp->next = newnode;
    }
    else if (isFound(item))
    {
      Node *temp = head;
      while (temp != NULL && temp->data != item)
      {
        temp = temp->next;
      }
      Node *newnode = new Node();
      newnode->data = newitem;
      newnode->next = temp->next;
      temp->next = newnode;
    }
  }

  // isfound to search
  bool isFound(int item)
  {
    Node *temp = head;
    bool found = false;
    while (temp != NULL)
    {
      if (temp->data == item)
        found = true;
      temp = temp->next;
    }
    return found;
  }

  // display
  void display()
  {
    Node *temp = head;
    cout << "[ ";
    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << " ]\n";
  }

  // count
  int count()
  {
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
      count++;
      temp = temp->next;
    }
    return count;
  }

  // delete
  int Delete(int item)
  {
    if (!isFound(item))
      return 0;
    Node *del = head;
    Node *prv = NULL;
    int value;
    if (!isEmpty())
    {
      if (head->data == item)
      {
        del = head;
        head = head->next;
        value = del->data;
        delete del;
      }
      else
      {
        while (del != NULL && del->data != item)
        {
          prv = del;
          del = del->next;
        }
        prv->next = del->next;
        value = del->data;
        delete del;
      }
    }
    return value;
  }
};

class algorthim
{
public:
  // buble sort for sorting array
  void bubleSort(int arr[], int length)
  {
    bool isSwapped = true;
    int i = 0;
    while (isSwapped)
    {
      isSwapped = false;
      for (int j = 0; j < length - i; j++)
      {
        if (arr[j] > arr[j + 1])
        {
          int temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
          isSwapped = true;
        }
      }
      i++;
    }
  }

  // selection sort for sorting array
  void selectionSort(int arr[], int length)
  {
    int i;
    int j;
    for (i = 0; i < length; i++)
    {
      int min = i;
      for (j = i + 1; j < length; j++)
      {
        if (arr[min] > arr[j])
        {
          min = j;
        }
      }
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }

  // insertion sort for sorting array
  void insertionSort(int arr[], int length)
  {
    int key, j;
    for (int i = 1; i < length; i++)
    {
      key = arr[i];
      j = i - 1;
      while (j >= 0 && arr[j] > key)
      {
        arr[j + 1] = arr[j];
        j--;
      }
      arr[j + 1] = key;
    }
  }

  // linear search in array
  bool linearSearch(int arr[], int item, int length)
  {
    bool isfound = false;
    int i = 0, index;
    while (i <= length)
    {
      if (item == arr[i])
      {
        isfound = true;
        index = i;
        break;
      }
      i++;
    }
    return isfound;
  }

  // binary search on sorted array
  int binarySearch(int arr[], int item, int length)
  {
    int start = 0;
    int end = length - 1;
    int mid;
    while (end >= start)
    {
      mid = start + (end - start) / 2;
      if (item == arr[mid])
        return mid;

      else if (item > arr[mid])
        start = mid + 1;
      else
        end = mid - 1;
    }
    return -1;
  }

  // min number on array
  int min(int arr[], int length)
  {
    int min = arr[0];
    for (int i = 0; i < length; i++)
    {
      if (arr[i] < min)
        min = arr[i];
    }
    return min;
  }

  // max number on array
  int max(int arr[], int length)
  {
    int max = arr[0];
    for (int i = 0; i < length; i++)
    {
      if (arr[i] > max)
        max = arr[i];
    }
    return max;
  }

  // checking if two common elements in two arrays
  bool isCommon(int arr1[], int arr2[], int length1, int length2)
  {
    for (int i = 0; i < length1; i++)
    {
      for (int j = 0; j < length2; j++)
      {
        if (arr1[i] == arr2[j])
          return true;
      }
    }
    return false;
  }

  // cheching for duplication of two arrays
  bool isDuplicate(int arr[], int length)
  {
    for (int i = 0; i < length; i++)
      for (int j = i + 1; j < length; j++)
        if (arr[i] == arr[j])
          return true;
    return false;
  }
};

class NodeStack
{
public:
  int data;
  NodeStack *next;
};
class Stack_Linedlist
{
private:
  NodeStack *top;
  int length;

public:
  Stack_Linedlist()
  {
    top = NULL;
    length = 0;
  }

  // isempty
  bool isEmpty()
  {
    return (top == NULL);
  }

  // push
  void push(int item)
  {
    NodeStack *newnode = new NodeStack();
    newnode->data = item;
    if (isEmpty())
    {
      newnode->next = NULL;
      top = newnode;
    }
    else
    {
      newnode->next = top;
      top = newnode;
    }
  }

  // pop
  int pop()
  {
    int value;
    if (!isEmpty())
    {
      NodeStack *temp = top;
      value = temp->data;
      top = top->next;
      delete temp;
    }
    return value;
  }

  // peek
  int peek()
  {
    return top->data;
  }

  // display
  void display()
  {
    NodeStack *temp = top;
    cout << "[ ";
    while (temp != NULL)
    {
      cout << temp->next << " ";
    }
    cout << " ]\n";
  }

  // clear
  void clear()
  {
    while (!isEmpty())
    {
      pop();
    }
  }
};

class NodeQueue
{
public:
  int data;
  NodeQueue *next;
};

class Queue_Linkedlist
{

private:
  NodeQueue *front;
  NodeQueue *rear;
  int length;

public:
  Queue_Linkedlist()
  {
    front = rear = NULL;
    length = 0;
  }

  // isempty
  bool isEmpty()
  {
    return (front == NULL);
  }

  // enqueue
  void enqueue(int item)
  {
    NodeQueue *newnode = new NodeQueue();
    newnode->data = item;
    if (isEmpty())
    {
      front = rear = newnode;
      length++;
    }
    else
    {
      rear->next = newnode;
      newnode->next = NULL;
      rear = newnode;
    }
  }

  // dequeue
  int dequeue()
  {
    int value;
    if (!isEmpty())
    {
      NodeQueue *temp = front;
      front = front->next;
      value = temp->data;
      delete temp;
    }
    return value;
  }

  // getfront
  int getFront()
  {
    return front->data;
  }

  // getrear
  int getRear()
  {
    return rear->data;
  }

  // display
  void display()
  {
    NodeQueue *temp = front;
    cout << "[ ";
    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << " ]\n";
  }

  // clear
  void clear()
  {
    while (!isEmpty())
    {
      dequeue();
    }
  }
};

class NodeTree
{
public:
  int data;
  NodeTree *right;
  NodeTree *left;

  NodeTree(int d)
  {
    data = d;
    right = left = NULL;
  }
};

class BST_Linkedlist
{
private:
  NodeTree *root;
  int length;

public:
  BST_Linkedlist()
  {
    root = NULL;
    length = 0;
  }

  // isempty
  bool isEmpty()
  {
    return (root == NULL);
  }

  // insert
  NodeTree *insert(NodeTree *r, int item)
  {
    if (r == NULL)
    {
      NodeTree *newnode = new NodeTree(item);
      r = newnode;
    }
    else if (item >= r->data)
      r->right = insert(r->right, item);
    else
      r->left = insert(r->left, item);

    return r;
  }
  // insert short
  void insert(int item)
  {
    root = insert(root, item);
  }

  // preorder traversal
  void displayPreOrder(NodeTree *r)
  {
    if (r == NULL)
      return;

    cout << r->data << " ";
    displayPreOrder(r->left);
    displayPreOrder(r->right);
  }

  // in_order traversal
  void displayInOrder(NodeTree *r)
  {
    if (r == NULL)
      return;

    displayInOrder(r->left);
    cout << r->data << " ";
    displayInOrder(r->right);
  }

  // post order traversal
  void dispalyPostOrder(NodeTree *r)
  {
    if (r == NULL)
      return;

    dispalyPostOrder(r->left);
    dispalyPostOrder(r->right);
    cout << r->data << " ";
  }

  // search
  NodeTree *search(NodeTree *r, int key)
  {
    if (r == NULL)
      return;
    else if (key == r->data)
      return r;
    else if (key >= r->data)
      return search(r->right, key);
    else
      return search(r->left, key);
  }

  // search short
  bool search(int key)
  {
    NodeTree *result = search(root, key);

    if (result == NULL)
      return false;
    else
      return true;
  }

  // find minimum
  NodeTree *minTree(NodeTree *r)
  {
    if (r == NULL)
      return NULL;
    else if (r->left == NULL)
      return r;
    else
      return minTree(r->left);
  }

  // find maximum
  NodeTree *maxTree(NodeTree *r)
  {
    if (r == NULL)
      return NULL;
    else if (r->right == NULL)
      return r;
    else
      return maxTree(r->right);
  }
};








int main()
{
  algorthim a;
  int ar[] = {34, 45, 2, 2, 2, 2, 5, 66, 1, 56, 6, 2, 0};
  int num[] = {1, 2, 3, 4, 4, 5};
  int si = sizeof(ar) / sizeof(ar[0]);
  int sn = sizeof(num) / sizeof(num[0]);
  // a.insertionSort(ar,si);
  // cout << a.isDuplicate(num,sn);

  // for(int i = 0; i < si; i++){
  //   cout << ar[i] << " ";
  // }
  // cout << endl;

  return 0;
}
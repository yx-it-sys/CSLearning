

# C++学习笔记



## 第1章 C++编程基础

### 1.7 容器Array与Vector的使用

**练习1.5**  编写一个程序，能够询问用户的姓名，并读取用户所输入的内容。请确保用户输入的名称长度大于两个字符。如果用户的确输入了有效名称，给予相应一些信息。

你的代码：

```c++
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
//using namespace std;
int main()
{
	std::string name;
	std::string name1("None");
	int chlan=0;
	while (chlan != 1 && chlan != 2) {
		std::cout << "Please choose the language: Chinese[1], English[2]\n";
		std::cin >> chlan;
		if (chlan == 1) {
			std::cout << "请输入您的名字：" << std::endl;
			std::cin >> name;
			std::cout << "欢迎，" << name << "!" << std::endl;
		}
		else if (chlan == 2) {
			std::cout << "Please enter your name: \n";
			std::cin >> name;
			std::cin >> name1;
			std::cout << "Welcome, " << name << " " << name1 << "!\n";
	}
	else {
		std::cout << "Please enter the right choice!\n";
		continue;
	}
}
return 0;
}
```

《Effective》答案：

```c++
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string user_name;

	cout << "Please enter your name: ";
	cin >> user_name;

	switch (user_name.size()) {
	case 0:
		cout << "Ah, the user with no name. "
			<< "Well, ok, hi, user with no name\n";
		break;

	case 1:
		cout << "A 1-character name? Hmm, have you read Kafka?: "
			<< "Hello, " << user_name << endl;
		break;

	default:
		cout << "Hello, " << user_name
			<< "--happy to make your aquaintance!\n";
		break;
	}
	return 0;
}
```

**练习1.6**  编写一个程序，从标准输入设备读取一串整数，并将读入的整数依次放到array及vector，然后遍历这两种容器，求取数值总和。将总和及平均值输出至标准输出设备。

我的代码：

1.array容器

```c++
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	const int len = 6;
	int arr[len], * p = arr;
	cout << "Please enter the data\n";

	int i = 0;
	for (i = 0; i < len; i++) {
		cin >> *(p+ i);
	}
	
	double sum = 0;
	for (int  j = 0; j < len; j++) {
		sum += *(p + j);
	}

	double ave = 0;
	ave = sum / len;

	cout << "The sum is: " << sum << endl
		<< "The average is: " << ave<<endl;
	return 0;
}
```

2.vector容器：



```C++
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	const int len = 6;
	vector<int> vec(len);
	cout << "Enter datum: \n";

	for (int i = 0; i < vec.size(); i++) {
		cin >> vec[i];
	}

	double sum = 0;
	double ave = 0;
	for (int j = 0; j < len; j++) {
		sum += vec[j];
	}

	ave = sum / len;

	cout << "The sum is: " << sum << endl
		<< "The average is " << ave << endl;
	return 0;
}
```

　array与vector的差别在于**（1）array的大小必须固定，而vector可以动态地随着元素的插入而扩展存储空间。（2）array并不存储自身大小。即array的大小在开始声明的时候就已经固定下来了，意味着我们必须考虑对它的访问可能导致溢出*（overflow）*。（3）array并没有像null字符那样的所谓“标兵”——用来表示已经到达末端。**

　建议初学者使用vector替代array。



标准答案：

```C++
//the container is vector
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> ivec;
	int ival;
	while (cin >> ival)
		ivec.push_back(ival);
			
	for (int sum=0, ix=0; ix < ivec.size(); ix++)
		sum += ivec[ix];
		
	int average = sum/ivec.size();
//根据C++ Standard, sum的作用范围局限于上述的for循环中。
//此处的sum会造成Undefined symbol的编译错误。只有某些编译器会让它过关。
//如何更改略

	cout << "Sum of "<<ivec.size()
		<< "element: " << sum
		<< ".Average: " <<average << endl;
	return 0;
}
```

```C++
//the container is array, be careful to monitor the size of elements writing into in case of being beyond //the boundary.

#include<iostream>
using namespace std;

int main()
{
	const int array_size = 128;
    int ia[array_size];
    int ival, icnt = 0;
    
    while(cin >> ival && icnt < array_size)
        ia[icnt++] = ival;
    
   int sum = 0;
    for(int ix=0; ix < icnt; ix++)
        sum += ia[ix];
    
    int average = sum/icnt;
    
    //code of output
    
    return 0;
}






```

**练习1.7**  输入两行文字并存盘。编写一个程序，打开该文本文件，将其中每个字都读取到vector<string>对象中。遍历该vector，将内容显示到 cout。然后利用泛型算法sort()，对所有文字排序：

```c++
#include<algorithm>
sort(container.begin(), container.end());

```

再将排序后的结果输出到另一个文件。

我的代码：

```C++
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
int main()
{
	string text;

	ofstream outfile("text.txt");
	if (! outfile)
	{
		cerr << "Can't open this file!";
	}
	else
	{
		outfile << "你好你好你好\n"
			<< "hellohellohello" << endl;
	}

	ifstream infile("text.txt");
	if (!infile) {
		cerr << "Can't open this file!";
	}
	else {
		while (infile >> text) {
			cout << text << endl;
		}
		sort(text.begin(), text.end());
		cout << text;
		ofstream outfile1("sort.txt");
		outfile1 << text;
		
	}

	return 0;
}
```

标准答案：

```c++
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ifstream infile("D:\\cpp programming\\My Documents\\text.txt");
	if (! infile) {
		cerr << "Unable to open input file\n";
		return -1;
	}

	ofstream outfile("D:\\cpp programming\\My Documents\\text.sort");
	if (!outfile) {
		cerr << "Unable to open output file\n";
		return -2;
	}

	string word;
	vector<string> text;
	while (infile >> word) {
		text.push_back(word);
	}

	int ix;
	cout << "Unsorted text:\n";
	
	for (ix = 0; ix < text.size(); ix++) {
		cout << text[ix] << ' ' ;
	}
	cout << endl;

	sort(text.begin(), text.end());

	outfile << "sorted text:\n";
	for (ix = 0; ix < text.size(); ix++) {
		outfile << text[ix] << ' ';
	}
	outfile << endl;

	return 0;
}
```

## 第二章 面向过程的编程风格(Procedural Programming)

### 2.1 如何编写函数

　每一个函数必须以下面的形式定义：

<center> 返回类型（没有返回值用void）+函数名+参数列表+函数体

　调用函数之前必须予以声明。函数声明不必提供函数体，但必须指明定义模式的前三项＋‘；’。

**引例**  用函数的方法写一个求斐波那契数列第i个元素的程序。

```C++
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int fibo(int pos);
	int a;
	cin >> a;
	cout << fibo(a);
	
	return 0;
}
int fibo(int pos) {
	int elem = 1;
	int n1=1, n2 = 1;
	int ix = 3;

	for (ix = 3; ix <= pos; ix++) {
		elem = n1 + n2;
		n2 = n1, n1 = elem;
	}
	return elem;
}
```

　该程序的漏洞在于过于信任用户，用户可能并不会知道传入的pos应该是正整数。可能会传入0或负数。如果犯下了这样的错误，程序最终会显示结果为1。那么，该如何改进？

　第一种是比较激进的方法，只要是传入的pos不是正整数，就直接退出程序

```C++
#include<cstlib>
//以状态值-1结束程序
if (pos <= 0){
    exit(-1);
}
```

　这样的方法过于不友善，而对于合适的解决方案——抛出异常（exception）将会在第七章介绍。

　下面介绍一个合理的修正方向

```c++
//重新修正函数原型
bool fibo(int pos, int &elem);
```

　函数只能有一个返回值。以上例子中，“Fibo()”能否计算出所指定的元素关系到其返回值为True或False。如何返回该元素的实际值，做法之一就是加入第二个参数：一个reference to *int*。下一节专门解释。

　以下是最终版本：

```c++
#include<iostream>
using namespace std;
int main()
{
	int pos;
	bool fibo(int , int &);
	cout << "Please enter a position: ";
	cin >> pos;

	int elem;
	if (fibo(pos, elem)) {
		cout << "element # " << pos
			<< " is " << elem << endl;
	}
	else cout << "Sorry. Could not calculate element # " << pos << endl;

	return 0;
}
bool fibo(int pos, int& elem)
{
	if (pos <= 0 || pos > 1024) {
		elem = 0; return false;
	}

	elem = 1;
	int n2 = 1, n1 = 1;

	for (int ix = 3; ix <= pos; ix++) {
		elem = n2 + n1;
		n2 = n1; n1 = elem;
	}
	return true;
}
```



### 2.2 调用函数

**实例** 设计一个可对vector内的整数值加以排序的函数。

**算法：**冒泡排序法

**算法思想：**当外层的for循环每次迭代完成，由ix索引出来的元素便已经放置在适当位置。当ix为0时，最小的元素会被找到，并置于位置0处；当ix=1时，第二小的元素会被找到，并放置在位置1处，以此类推。 

**流程图：**

```flow
s=>start: 开始
i1=>inputoutput: 输入a[N]
j=>operation: j=0
i=>operation: i=0
cond1=>condition: a[i]<a[i+1]?
ipp=>operation: i++
jpp=>operation: j++
swap=>operation: t=a[i];
a[i]=a[i+1];
a[i+1]=t;
cond2=>condition: i<N-j?
cond3=>condition: j=N?
o=>inputoutput: 输出a[N]
e=>end: 结束
s->i1->j->i->cond1
cond1(yes)->swap
cond1(no)->ipp
ipp->cond1
swap->cond2
cond2(no)->jpp
jpp->cond3
cond3(yes)->o
cond2(yes)->ipp
cond3(no)->i
o->e

```

**实现代码：**

```c++
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

//遍历vector函数
void display(vector<int> vec)
{
	for (int ix = 0; ix < vec.size(); ix++) {
		cout << vec[ix] << ' ';
	}
	cout << endl;
}

//交换函数
void swap(int val1, int val2)
{
	int t = val1;
	val1 = val2;
	val2 = t;
}

//冒泡法排序
void bubble_sort(vector<int> vec)
{
	for (int ix = 0; ix < vec.size(); ix++) {
		for(int jx = ix + 1; jx < vec.size(); jx++) {
			if (vec[ix] > vec[jx])
				swap(vec[ix], vec[jx]);
		}
	}
}

int main()
{
	int ia[8] = { 8,34,3,13,1,21,5,2 };
	vector<int> vec(ia, ia + 8);

	cout << "vector before  being sorted: ";
	display(vec);

	bubble_sort(vec);

	cout << "vector after being sorted: ";
	display(vec);

	return 0;
}
```

　运行这个程序，我们发现并没有实现vector中的数从小到大排序

![Alt text](result1.png"上述程序运行结果")



　问题出在了哪里，学过C语言，很容易发现问题出在了swap函数上，如果最终没有实现元素的交换，就说明传入函数的两个参数`vec[ix]`与`vec[jx]`和`swap()`函数的两个参数除了值相同以外，并没有联系。

　当我们调用一个函数时，会在内存中建立起一块特殊的区域，称为**程序堆栈(program stack)**。这块特殊的区域提供了每个**函数参数**的存储空间。它也提供了**函数所定义的每个对象**的内存空间——我们将这些对象称为**local object（局部对象）**。**一旦函数完成，这块的内存就会被释放掉，或者说是从程序堆栈中被*pop*出来**。

   当我们将`vec[ix]`这样的对象传入函数，默认情形下其值会**复制一份**，成为参数的局部性定义(local definition)。这种方式被称为**传值(pass by value)**。我们在`bubble_sort()`内传给`swap()`的对象，和我们在`swap()`内操作的对象，其实是**没有任何关系的两组对象**。

　如何令`swap()`的参数和传入的实际对象产生关联？要采用**传址(pass by reference)**的方法。

　采用传址的方法的程序应是

```c++
//交换函数
void swap(int& val1, int& val2)
{
	int t = val1;
	val1 = val2;
	val2 = t;
}
```



```c++
//冒泡法排序
void bubble_sort(vector<int> &vec)
```



#### Pass by Reference 语义

```C++
int ival = 1024;	//对象，类型为int
int *p = &ival;		//pointer，指向一个int对象
int &rval = ival;	//reference（引用），代表一个int对象，rval是对ival的引用，是ival的别名
const int& z = x;   //z是x的别名，通过z不可以修改x！
```

```c++
void f(int& x);
f(y); //y是x的引用
```

**引用必须要有位置，即变量名，否则会出错。**

**C++不允许我们改变reference所代表的对象，它们必须从一而终。**因此，当我们这么写

```C++
int &rval = ival;
int jval = 1024;
rval = jval;
```

是错误的。

　传址能够是函数形参和传入的实际参数产生关联的原因是，传入的变量，经过取地址运算得出的地址传入到程序堆栈之中，因为每一个变量和它所在的地址都是一一对应的，最终会间接地作用于变量。

　C语言常用的传址方式是定义一个指针

```C++
void func(int *p)
```

这实际上和

```C++
void func(int &val)
```

是等价的，两个运算是互逆的，相比较vector以pointer传递，以reference传递显得更加直接，因为val是变量，程序中已经存在，而且直观；p是指针，属于脱离与程序创造出的新变量，不那么直观。

```c++
int* f(int* x){
    (*x) ++;
    return x;
}
int& g(int& x){
    x ++;
    return x;
}

int x;

int& h(){
    int q;
    //return q; //ERROR
    return x;
}
```

reference可以做左值：

```c++
int x;
int& h(){
    return x; //实际上是将全局变量x变成reference给返回
}
int main()
{
    h() = 16; //OK! x=16
    int a = 0;
    g(a); //不易被理解，而且a也可能会被x改变
}
```



　以上探讨了pass by refernce的作用之一：希望得以直接对所传入的对象进行修改。还有一个略显不那么重要的理由是使程序的效率提高。传入参数的过程是复制变量存储的数据的过程，而直接传入指针，没有复制的这一步。例如将display函数的调用方式改成

```C++
void display(const vector<int> &vec)
{
    for(int ix = 0; ix < vec.size(); ix++){
        cout << vec[ix] << ' ';
        cout << endl;
    }
}
```

避免了复制操作。其中，我定义了const类型的变量，主要起强调作用，强调vec不会发生改变。实际上，少了*const*程序也不会报错。

　reference和pointer的用法不太相同，区别在于使用pointer使一定确保指针非零，因为指针可能指向其他奇奇怪怪的对象。reference必须依附于某一变量，而且一旦指定，便不可被修改。

**Reference的限制：**

1. 没有引用的引用。
2. 没有指向reference的指针。
3. 有指针的reference（指针的别名）。
4. 没有引用数组，reference不是一个实体。

#### 作用域及范围

　　 函数只是暂时位于程序堆栈之上，当函数执行完毕，这块区域的内存就会被pop掉，局部对象将不复存在。因此，对局部对象进行寻址操作，无论以pointer还是reference将函数值返回，都不正确。

​		为对象分配的内存，其存活时间称为**储存期(storage duration)**，也叫生存期或范围(extent)。每次函数执行，都会为局部变量分配内存，函数执行结束时便会加以释放。我们称此对象具有**局部性范围(local extent)**。

​		对象在程序内的存活区域称为该对象的**作用域(scope)**。函数内的所有局部变量拥有局部作用域(local scope)。

​		对象在函数以外声明，具有所谓的file scope。file scope内的对象具有**全局生存期(static extent)**，意即该对象的内存在main()开始执行时便已经分配好了，可以一直存在至程序结束。

​		**内置类型的对象，如果定义在file scope内，必定会被初始化为0.但如果定义于local scope之内，那么除非程序员指定其初值，否则不会被初始化。**

#### 动态内存管理

​		上边提到的file scope和local scope，都是由系统自动管理。第三种存储期形式称为dynamic extent（动态范围）。其内存系由**空闲空间(free store)**分配而来，有时也称为**heap memory（堆内存）**。这种内存必须由程序员自己管理，分配由`new`表达式完成，其释放通过`delete`来完成。

​		`new`的表达式形式如下：

```C++
new Type:
```

此处的`Type`可以是任意的内置类型，也可以是程序知道的`class`类型。`new`的表达式亦可写成：

```C++
new Type(initial_value);
```

例如，

```C++
int *pi;
pi = new int;
```

先由heap分配出一个类型为int的对象，再将其赋值给pi。默认情形下，由heap分配而来的对象，**皆未经初始化**。如何进行初始化赋值？

```C++
int *pi;
pi = new int(1024);
```

这个对象的值会被初始化为1024.

```C++
int *pia = new int[24];
```

上述代码则会从heap分配一个数组，拥有24个整数。pia会被初始化为数组第一个元素的地址。C++没有提供任何语法让我们得以从heap分配数组的同时为其元素设定初值。

​		从heap分配来的对象，在new表达式分配之后便一直存在，直到表达式`delete`加以释放为止。

```C++
//释放pi所指的对象
delete pi;
//释放数组中的所有对象
delete [] pia;

```

注意，**无须检查pi是否非零**。这样做多此一举，因为编译器会自动检查。

​		如果程序员不用`delete`释放内存空间，对于大型的程序或者长久使用会造成很大的麻烦，由heap分配而来的内存永远不会被释放，称为memory leak（内存泄漏）。第六章会查看什么时候应该采用动态内存分配，第七章会谈到如何预防内存泄漏的发生。

###  2.3 提供默认参数值

​		一般的程序编写规则是，以“参数传递”作为函数间的沟通方式，比直接将对象定义于“file scope”更适当。因为如果函数过度依赖定义于file scope内的对象，就比较难以在其他环境中再次使用，丧失了使用范围的普遍性；同时也比较难以修改——不仅需要了解该函数的工作逻辑，也必须了解定义于file scope中的那些对象的工作逻辑。

​		下面是一个例子——调试冒泡排序程序，将跟踪信息打印到`ofil`

```C++

//冒泡法排序
ofstream ofil("text_out1");
void bubble_sort(vector<int> &vec)
{
	for (int ix = 0; ix < vec.size(); ix++) {
		for(int jx = ix + 1; jx < vec.size(); jx++) {
			if (vec[ix] > vec[jx]) {
				ofil << "about to call swap!"
					<< "ix: " << ix << "jx: " << jx << '\t'
					<< "swapping: " << vec[ix]
					<< "with" << vec[ix] << endl;
				swap(vec[ix], vec[jx]);
			}
		}
	}
}
```

这串代码，将`ofil`定义在了file scope中，应该对`bubble_sort()`做出怎样的修改，才能使它摆脱对file scope内`ofil`的依赖：

```C++
void bubble_sort(vector<int> &vec, ofstream &ofil)
{
	for (int ix = 0; ix < vec.size(); ix++) {
		for(int jx = ix + 1; jx < vec.size(); jx++) {
			if (vec[ix] > vec[jx]) {
				ofil << "about to call swap!"
					<< "ix: " << ix << "jx: " << jx << '\t'
					<< "swapping: " << vec[ix]
					<< "with" << vec[ix] << endl;

				swap(vec[ix], vec[jx]);
			}
		}
	}
}

int main()
{
	//...

	ofstream ofil("debug.txt");
	bubble_sort(vec,ofil);
   //...
	return 0;
}
```

改代码虽然实现了函数的独立性，但是，每次调用的时候总是要传入ofstream对象，而且用户户无法关闭我们所产生的信息。我们希望用户不但不必指定输出用的stream，而且有能力把输出信息关闭。默认情形下我们不想产生这些信息，但是又希望让那些想要看到这些信息的users可以产生它们，甚至指定其输出文件。该怎么办？C++允许我们为全部或部分参数**设定默认值**。本例中，可以将其中的`ofstream`指针默认设置为0：

```c++
void bubble_sort(vector<int> &vec, ofstream *ofil = 0)
{
	for (int ix = 0; ix < vec.size(); ix++) {
		for(int jx = ix + 1; jx < vec.size(); jx++) {
			if (vec[ix] > vec[jx]) {
				ofil << "about to call swap!"
					<< "ix: " << ix << "jx: " << jx << '\t'
					<< "swapping: " << vec[ix]
					<< "with" << vec[ix] << endl;

				swap(vec[ix], vec[jx]);
			}
		}
	}
}
```

​		有了这样的改变，我们就可以选择是否生成调试信息

```c++
void display(const vector<int> *vec, ofstream ofil)
{
	for (int ix = 0; ix <  vec-> size(); ix++) {
		cout << (*vec)[ix] << ' ';
		ofil << (*vec)[ix] << ' ';
	}
	cout << endl;
	
}

void bubble_sort(vector<int> &vec, ofstream *ofil = 0)
{
	for (int ix = 0; ix < vec.size(); ix++) {
		for(int jx = ix + 1; jx < vec.size(); jx++) {
			if (vec[ix] > vec[jx]) {
				ofil << "about to call swap!"
					<< "ix: " << ix << "jx: " << jx << '\t'
					<< "swapping: " << vec[ix]
					<< "with" << vec[ix] << endl;

				swap(vec[ix], vec[jx]);
			}
		}
	}
}

int main()
{
	int ia[8] = { 8,34,3,13,1,21,5,2 };
	vector<int> vec(ia, ia + 8);
	
	cout << "vector before  being sorted: ";
	display(&vec);
	//产生调试信息
	ofstream ofil("debug.txt");
	bubble_sort(vec, ofil);
	display(vec, ofil);
    
    //不产生调试信息
    bubble_sort(vec);
    display(vec);
    
	cout << "vector after being sorted: ";
	display(&vec);

	return 0;
}
```

该程序的`display()`函数始终会将输出写到`cout`之中，如何是其可以选定写到`cout`之中，还是`ofil`之中？

```c++
void display(const vector<int> &vec, ostream &os = cout)
{
    for(int ix = 0; ix < vec.size(); ix++)
        os << vec[ix] << ' ';
    os << endl;
}
```

不传入`os`值，默认传入cout之中；传入`os`值，传入指定的`ofill`之中。

​		关于默认参数值的提供，有两个规则。第一个规则是，默认值的解析操作(resolve)由**最右边**开始进行。如果我们为某个参数提供了默认值，那么这一个参数的右侧的所有参数都必须具有默认参数值才行。下面这样实属非法：

```c++
//错误！没有为vec提供默认参数值
void display(ostream &os = cout, const vector<int> &vec);
```

第二个规则是，默认值只能够指定一次，可以在函数声明处，也可以在函数定义处，但**不能够声明处和定义处两个地方都指定**。为了更高的可见性，规范的写法是将默认值放在**函数声明处**而非函数定义处。因为函数声明通常会被**放在头文件**中。因此，`display()`的声明和定义通常会是下面这样：

```c++
//头文件声明，其中制定了默认参数值
//暂且称此例中头文件为NumericSeq.h

void display(const vector<int>&, ostream & = cout);

//程序代码包含上述头文件，至于函数定义处，并没有指定参数的默认值。

#include "NumericSeq.h"

void display(const vector<int> &vec, ostream &os)
{
    for(int ix = 0; ix < vec.size(); ix++)
        os << vec[ix] << ' ';
    os << endl;
}
```

### 2.4 使用局部静态对象

​		我们在设计一个Fibonacci数列的函数是，计算出x对应的Fibonacci数。只需调用该函数即可求得

```c++
fibon_seq(24);
fibon_seq(8);
fibon_seq(18);
```

这样的程序，实际上是做了一些不必要的冗余工作的。因为在计算完`fibon_seq(8)`之后，再计算`fibon_seq(18)`，函数会重新从1开始递归计算。因为函数的形参在执行之后就会被pop掉，没有存储功能。这样显然是没有效率的。倘若我此次还要计算32个元素的值，如果具有存储功能，我只需要计算#25-#32的数值。这要如何办到？

​		有一种想法是将vector对象定义在file scope之中，这样做是在冒险！**为了节省函数之间的通信问题而将对象定义于file scope内，永远都是一种冒险。通常file scope对象会打乱不同函数之间的独立性，使它们变得难以理解。**

​		一个比较好的想法是使用**局部静态对象(local static object)**。例如

```c++
const vector<int>*
fibon_seq(int size)
{
    static vector<int> elems;
    //...
    
    return elems;
}
```

此刻的elems被定义为`fibon_seq()`中的局部静态对象。局部静态对象具有**全局生存期和局部作用域**。局部静态对象所处的内存空间，即使不再函数调用的过程中，依然持续存在。

```C++
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

const vector<int>*
fibon_seq(int size)
{
	const int max_size = 1024;
	static vector<int>elems;

	if (size <= 0 || size > max_size) {
		cerr << "fibon_seq(): oops:invalid size: "
			<< size << "--can't fulfill request.\n";
		return 0;
	}

	for (int ix = elems.size(); ix < size; ix++) {
		if (ix == 0 || ix == 1) {
			elems.push_back(1);
		}
		else elems.push_back(elems[ix - 1] + elems[ix - 2]);
	}
	return &elems;
}
```



### 2.5 提供重载函数(Function Overloading)

​		假设我们已经写好了一个通用的函数`display_message()`用来显示我们需要显示的信息。我们可能需要显示一串数字，也可能是一段字符，也可能是转义字符`\t\n`。但是我们定义函数的时候，参数列表已经唯一地指定。这样过于僵硬，我们想要让其灵活地实现显示各种数据类型的对象。怎么办？通常，一个函数的定义全部由定义该函数的所有性质决定：函数名，返回值类型，参数列表，函数体。由集合的外延公理，性质有一个不一样，那么整个函数就是不一样的函数，例如

```C++
void display_message(char ch);
void display_message(const string&);
void display_message(const string&, int);
void display_message(int, const string&);
void display_message(const string&, int, int);
```

实际上这是五个不同的函数，但是具有相同的函数名，我们称其为**函数的重载**。函数的重载实际上是有编译器将C++代码转换成汇编语言的时候，会对重载的函数名称进行改动。我们要讨论重载函数的正确使用方法。

​		编译器**无法根据函数返回类型来区分两个具有相同名称的函数。**以下是不正确的写法：

```c++
//错误！！！参数列表必须不同！
ostream& display_message(char ch);
bool display_message(char ch);
```

原因是，比如以下的代码

```c++
display_message('\t');//到底是哪一个函数呢？
```

​		将一组实现代码不同但工作内容相似的函数加以重载，可以让函数用户更容易使用这些函数。如果没有函数重载机制，我们就得为每个函数提供不同的名称。

### 2.6函数默认参数（缺省参数值）

函数的默认参数值是在进行函数声明时，给参数列表中的参数提供一个值的方法，如果你不提供一个默认的参数值，编译器也会自动提供一个默认的参数值。

```c++
int main(){
Stash(int size, int initQuantity = 0);
Stash(1); //OK
Stash(1,3); //OK
}
```

在参数表中传入默认参数值的时候，默认值的传递要从最右端开始写：

```c++
int harpo(int n, int m=4, int j=5);
int chicho(int n, int m=6, int j); //illegal
```

Default argument写在头文件中，不能再.cpp文件中重复

```c++
//a.h
void f(int i, int j=0);                       /**/
//a.cpp
#include "a.h"
void(int i, int j=0){                         /**/
    cout << i << " " << j << endl;
}
//main.cpp
#include"a.h"
int main()
{
    f(10);
    return 0;
}
```

**程序错误："f"重定义默认参数。**如果不在头文件中给j提供默认参数，而在a.cpp中提供呢？**程序错误："f"函数不接受默认参数**。

默认参数值是在编译的时候进行的事情，而非运行，函数其实还是要了两个参数，编译器看到了函数的原型声明，补上了相应的参数值。

下面是证据：

```c++
//a.h
int f(int i, int j=0);
//main.cpp
#include<iostream>
void f(int i, int j=10);
int main()
{
    f(10);
    return 0;
}
```

输出结果：10	10

**不要使用Default Value，没有太多实际意义且不安全**。

### 2.7 声明inline函数

​		模块化、程式化编程一直以来都是编写程序所恪守的原则。所谓模块化，就是将程序以最简单的逻辑设计。每个逻辑节点通常是某种动作功能。这一动作功能为一函数。

​		这样的设计，使得每一个函数只实现一个功能。但是有些时候，编译过程中编译的函数过多会降低程序运行的性能。**Overhead for a function call**调用函数存在着“额外的开销”，这是汇编层面的事情。（push and pop）

​		将函数声明为inline，表示编译器在每个函数调用点上，将函数的内容展开。面对一个inline函数，编译器可将该函数的调用操作改为以**一份代码副本**代替，原封不动地嵌入到要调用它的地方去，**但依然维持独立的运算单元**。

```c++
int f(int i){
    return i*2;
}
int main()
{
    int a = 4;
    int b = f(a);
}
//修改为inline
inline int f(int i)
{
    return i*2;
}
int main()
{
    int a = 4;
    int b = f(a); //八f()的代码转移到这里
    /*17行语句实际上是这个样子*/
    int b = a + a;
}
```



​		在函数返回类型之前加上关键字inline，可以解决一些频繁调用的函数大量消耗栈空间（栈内存）的问题。引入inline函数是为了替代**C中表达式的宏定义**。

<center> #define	ExpressionName(Var1, Var2) ((Var1+Var2)*(var1-Var2))




这种宏定义效率很高，**但是仅仅是符号表中的简单替换，不能享受C++编译器严格检查的好处，它的返回值也不能被强制转换为合适的类型。**inline函数克服了这一缺陷。因此实际上设置成inline的函数，就相当于宏定义中的符号替换。

​		一般而言，最适合声明为inline的函数：**体积小，常被调用，（比如循环体）、所从事的计算并不复杂**。

​		值得一提的是。将函数指定为inline，只是对编译器提出的一种要求。编译器是否执行这样的要求，须视编译器而定。inline函数的定义，常常被放在头文件中。**关键字inline必须与函数定义放在一起才能使函数成为内联函数，仅仅将inline函数放在函数声明前不起任何作用。**

不同于给函数提供默认参数，在头文件中传入默认参数在.cpp程序文件中就不能重复声明，inline函数必须在头文件中和.cpp文件中**同时声明**。“Repeat inline keyword at declaration and definition”.

不重复声明，编译器会报错：

<img src="https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202303032139745.png" alt="image-20230303213956500" style="zoom:80%;" />

正确做法是把inline函数的函数体放入到头文件之中。加上inline的函数，这个时候函数体**成为声明而非定义**。注：声明可以重复，但是定义不能。

对于成员函数，在类的声明时就写出了它的函数体，这个时候**它默认成为内联函数。**在头文件中，为了使class类规整简单，可以在类中只给出函数的声明，而在声明类的花括号结束之后，写出函数的定义，这个时候要加上inline关键字。

### 2.8 Const

被定义成了const的变量，不可修改其值。本质上，它依旧是一个变量，只不过编译器不允许程序操作者对其进行修改。

```c++
const int class_size = 12;
int finalGrade[class_size]; // OK

int x;
cin >> x;
const int size = x;
double classAverage[size]; //ERROR!
```

<img src="https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202303040947809.png" alt="image-20230304094701563" style="zoom:80%;" />

const是编译器进行的操作，第二个代码在编译的过程中并不明确const size的值，因而无法为const变量分配相应大小的内存空间。

**const与指针**

指针可以是const，指针所指的对象也可以是const

```c++
char * const q = "abc"; //q is const
*q = 'c'; // OK
q++; //ERROR!

const char* p = "abcd"; //(*p) is a const char.**不能通过p去修改所指向的对象，不是说指到哪里，哪里变成const！！**
*p = 'b'; //ERROR!
```

```c++
Person p1("Fred", 200);
const Person* p = &p1; //p所指对象是const
Person const* p = &p1; //p所指对象是const
Person *const p = &p1; //指针本身是const
const Person * const p = &p1; //指针和对象都是const
```

**写在 * 前面，表示指针所指对象是const；写在 * 后面，表示指针是const**。

```c++
int* ip;
const int* cip; //cip所指的对象是const

int i;
ip = &i;
cip = &i; //OK，不能通过cip去修改 i

const int ci = 3;
ip = &ci; //ERROR! ip不是指向const，可以对ci进行修改，可是ci不可以被修改
cip = &ci; //OK, cip不可以修改ci，ci本身就不允许被修改
```

`const int *`表示**不可以通过指针去修改所指的对象**。

```c++
int main()
{
    char* s = "hello world";
    cout << s << endl;
    s[0] = 'b';
    cout << s << endl;
}
```

<img src="https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202303041020575.png" alt="image-20230304102030265" style="zoom:80%;" />

`"hello world`"是字符串常量。s是本地变量，在堆栈里面，s指向`"hello world"`所在的内存。变量被放置在内存的不同的位置中，本地变量放在**堆栈**内；自己申请的内存位于**堆**中；全局变量在**全局数据区内**；常量，例如字符串常量`"hello world"`，处于**代码段**中。现代操作系统，MMU会对代码段进行保护，使得代码段都不可写。试图做这样的事情，会出现“segmentation fault”的错误。

```c++
#include<iostream>
using namespace std;
int main()
{
	//const char* s = "hello world"; //这句会使第8行代码出错
	char s[] = "hello world"; //和第5行的区别是，s是一个数组，位于堆栈内。“=”实际进行的是拷贝的工作，将代码段的字符串常量拷贝到堆栈内的数组s中
	cout << s << endl;
	s[0] = 'B';
	cout << s << endl;
}
/*以上是正确的写法*/
```

**const对象**

对象的值不可修改，那么函数可能就不被允许使用。怎么知道那些函数会对对象的值进行修改？就需要去查看源码。在一个函数后面加上const，保证这个函数不会去修改这个对象的变量：

```c++
int Date::set_day(int d){
    day = d;
}

int Date::get_day() const{
    day++; //ERROR! 不可以修改对象的值
    set_day(12); //ERROR！不能访问非常量的成员！
    return day;
}
```

const声明和原型都要定义。函数后面写上const，实际上是把this变成了const

```c++
#include<iostream>
using namespace std;
class A {
	int i;
public:
    A():i(0){}
	void f() { cout << "f()" << endl; } //void f(A* this)
	void f() const { cout << "f() const" << endl; } //void f(const A* this)
};
int main()
{
	const A a;
	a.f();
	return 0;
}
```

结果：f() const

当对象中的某一成员变量被设置为const，那么就要在类中对其进行初始化。在initialized list对其进行初始化。

回到本节的的一个例子，可以用枚举的方法给数组传入size

```c++
class HasArray{
    enum{size = 100};
    int array[size]; //OK
}
```



### 2.9 定义并使用模板函数 

​		函数模板(function template)提供了这样的一个机制：将单一的函数内容与希望显示的各种vector类型绑定(*bind*)起来。function template将参数列表中指定的全部或部分参数的类型信息抽离了出来。在`display_message()`中，我们希望将vector所持的元素类型抽离出来，这样就可以定义出一份不需要再有任何更改的模板。不过这样，我们便遗漏了抽离出来的类型信息。这份类型信息系由用户提供——当他决定采用function template的某个实例时提供。

​		function template以关键字`template`开场，紧接着以成对的尖括号（<>）包围起来的一个或多个标识符。这些标识符表示我们**希望推迟决定的数据类型**。例如：

```c++
template <typename elemType>
void display_message(const string& msg, const vector<elemType>& vec)
{
	cout << msg;
	for (int ix = 0; ix < vec.size(); ix++) {
		elemType t = vec[ix];
		cout << t << ' ';
	}
}
```

**关键字`typename`表示**，elemType在`display_message()`函数中是一个**暂时放置类型的占位符**。`elemType`只是个任意名称。函数的第一个参数msg在每次调用的时候类型都不会变，一直是一个const reference to*string object*，没有将其类型抽离出来。function template的参数列表通常是由两种类型构成，一种是明确的类型，另一类是暂缓决定的类型。

​		我们应当如何使用function template？使用方式和普通函数极其相似。例如

```c++
vector<int> ivec;
string msg;
//...
display_message(msg, ivec);
```

编译器会将`elemType`绑定为`int`类型，然后产生一份`display_message()`的函数实例，于是其第二参数类型变成`vector<int>`。

​		一般而言，如果函数具备多种实现方式，我们可以将它重载，其每份实例提供的是相同的服务。如果我们希望程序代码主体不变，仅仅改变其中用到的数据类型，可以通过function template达到目的。function template也可以是重载函数。例如

```c++
//function template再经重载
template <typename type>
void display_message(const string &msg, const vector<type> &vec);

template <typename type>
void display_message(const string &msg, const list<type> &lt);
```

### 2.10 函数指针带来更大的弹性

现在要设计一个可以通过vector返回Fiboncci、"Lucas"、"Pell"、"triangle"、"square"、"Pent"六种数列的函数。做法之一就是定义一下一整组函数：

```C++
const vector<int> *fibon_seq(int size);
const vector<int> *lucas_seq(int size);
const vector<int> *pell_seq(int size);
const vector<int> *triang_seq(int size);
const vector<int> *square_seq(int size);
const vector<int> *pent_seq(int size);
```

那么fibon_elem()呢？难道也必须针对所有数列提供六个不同的函数？fibon_elem()定义如下：

```C++
bool fibon_elem(int pos, int &elem)
{
    const vector<int> *pseq = fibon_seq(pos);	// (A)
    
    if(! pseq)
    {elem = 0; return false;}
    
   elem = (*pseq)[pos - 1];
   return true;
}
```

**在`fibon_elem()`的定义中，唯一和数列关联的部分，只有（A）。如果我们可以消除这个关联，便可以不必提供多个类似的`fibon_elem()`函数了。**我们可以使用指针来达到这个目的.

​		函数指针的形式是函数名前有一个*号，在本例中，参数列表为`int`，返回类型为`const vector<int> *`。因此，定义函数的形式为：

```C++
				const vector<int>* *seq_ptr(int); // almost right.
```

这一行的函数返回类型是二级指针，这一行将`seq_ptr`定义成一个函数，参数列表中仅有一个`int`类型，返回类型是一个指针，这个指针指向另一个指针，后者指向一个`const vector<int>`。为了让`seq_ptr`被视为一个指针，要用小括号改变运算优先级：

```c++
				const vector<int>* (*seq_ptr)(int);
```

​		现在，`seq_ptr`可以指向**具有所列返回类型及参数列表的任何一个函数**。这意味着，它可以分别指向前述六个数列函数，前面写过的`fibon_elem()`就可以变成更为通用的`seq_elem()`：

```c++
bool seq_elem(int pos, int& elem, const vector<int>* (*seq_ptr)(int))
{
	const vector<int>* pseq = seq_ptr(pos);

	if (!pseq) {
		elem = 0; return false;
	}

	elem = (*pseq)[pos - 1];
	return true;
 }
```

由函数指针指向的函数，其调用方式和一般函数相同，也就是说，

```c++
const vector<int> *pseq = seq_ptr(pos);
```

会间接调用`seq_ptr`所指向的函数。我们不关注它所指向的函数是哪一个。严谨一些，就是要多付出一些检验工作，确定它是否真的指到某个函数：

```c++
if(! seq_ptr)
    display_message("Internal Error: seq_ptr is set to null!");
```

我们可以给予函数指针初值。如果初值为0，表示并未指向任何函数：

```c++
const vector<int>* (*seq_ptr)(int) = 0;
```

如何取得函数的地址？只需要提供函数名称即可：

```c++
seq_ptr = pell_seq;
```

​		如果我希望编写一个循环，在每次迭代过程中将`seq_ptr`设置为不同的数列函数（而非一一写出数列函数的名称）该如何办到呢？我们可以定义一个数组，内放函数指针：

```c++
//seq_array是个数组，内放函数指针
const vector<int>* (*seq_array[])(int) = {fibon_seq, lucas_seq, pell_seq, triang_seq, square_seq, pent_seq};
```

​		当用户想继续猜想另一个数列时，我们可以在`while`循环的迭代中设定`seq_str`的值：

```C++
int seq_index = 0;
while(next_seq == true)
{
    seq_ptr = seq_array[seq_index++];
    //...
}
```

​		如果我们想要以明确指定函数的方式来产生Pell数列，又该怎么办呢？我们可以采用**枚举类型**来进行索引操作，例如：

```c++
enum ns_type{
    ns_fibon, ns_lucas, ns_pell, ns_triang, ns_square, ns_pent
};
```

默认情形下，以ns_type为例，ns_fibon的值为0，ns_lucas的值为1，......为了以明确指定的方式取用函数指针，我们使用对应的枚举项作为数组索引值：

```c++
seq_ptr = seq_array[ns_pell];
```

### 2.11 设定头文件

​		调用函数之前必须先声明，如果该函数备多个程序文件调用，多次声明操作低效。为了不用分别在每个文件中声明，吧函数声明放在头文件中，并在每个程序代码中包含这些函数声明。

​		头文件的扩展名，习惯是`.h`**标准库例外，它们没有扩展名**。例如，我们将我们的头文件命名为`Numseq.h`，并将与数列处理有关的所有函数声明都放在该文件中：

```c++
//NumSeq.h
bool seq_elem(int pos, int &elem);
const vector<int> *finbn_seq(int size);
const vector<int> *lucas_seq(int size);
const vector<int> *pell_seq(int size);
const vector<int> *triang_seq(int size);
const vector<int> *square_seq(int size);
const vector<int> *pent_seq(int size);
```

​		函数的定义**只能有一份**，函数的声明**可以有许多份**。只定义一份的规则有个例外：**inline函数的定义**。为了能够扩展inline函数的内容，在每个调用点上，编译器都得取得其定义。这意味着我们必须将inline函数的定义**放在头文件中**，而不是把它放在各个不同的程序代码文件之中。

​		在file scpoe内定义的对象，如果可能被多个文件访问，就应该声明在头文件中。举个例子，如果`seq_array`被定义于file scope，我们会想要在`NumSeq.h`内提供它的声明。但是这样的形式并不正确：

```c++
const int seq_cnt = 6;
const vector<int>* *(seq_array[seq_cnt])(int);
```

它会被解读为`seq_array`的定义而非声明。需要在上述`seq_array`定义前面加上关键字extern，它便成为一个声明。

```c++
extern const vector<int>* (*seq_array[seq_cnt])(int);
```

​		为什么`seq_cnt`定义时不需要加`extern`呢？这是一个尖锐又晦涩但是很重要的问题。`const`object和inline函数一样，是“一次定义”规则下的例外。`const`object的定义只要一出文件之外便不可见。这意味着我们可以在多个程序代码文件中加以定义，不会导致任何错误。**注意，`const vector<int>*`是指向`const`object的指针，它本身并不是`const`object。**

任何需要用到`seq_elem()`或`seq_array`的文件，在它们第一次使用这两个名称时，都必须include对应的头文件：

```c++
#include "NumSeq.h"
```

什么时候使用双引号，什么时候使用尖括号？如果此文件被认定为标准的或项目专属的头文件，便使用尖括号；编译器搜索此文件时，会先在某些默认的磁盘目录中寻找。如果文件名由成对的双引号括住，此文件便被认为是一个用户提供的头文件；搜索此文件时，会从要包含此文件的文件所在的磁盘目录开始找起。简单一句话就是：**如果头文件和包含此文件的程序代码文件位于同一个磁盘目录下，我们便使用双引号。不在，则使用尖括号。**

### 练习

**练习 2.2** Pentagonal数列的求值公式是
$$
P(n)=\dfrac{n(3n-1)}{2}
$$
借此产生1,2,12,22,35等值。试定义一个函数，利用上述公式，将产生的元素放到用户传入的vector中。元素个数由用户指定。请检查元素个数的有效性（太大则会引起overflow的问题）。接下来编写第二个函数，能够将给定的vector的所有元素一一打印出来。此函数的第二个参数接受一个字符串，表示存放在vector内的数列的类型。最后再写一个main，测试上述两个函数。

```c++
#include<iostream>
#include<vector>
#include<fstream>
#include<math.h>
using namespace std;

bool pen(int size, vector<int>& elems)
{
	if (size <= 0 || size > 1024) {
		cerr << "Invalid size: " << size << endl;
		return false;
	}
	else {
		for (int ix = elems.size(); ix <= size;++ix) {
			elems.push_back(ix * (3 * ix - 1) / 2);
		}
		return true;
	}
}

void display(vector<int>& vec, const string& title,  ostream& os=cout) {
	os << '\n' << title << "\n\t";

	for (int ix = 0; ix < vec.size(); ++ix)
		os << vec[ix] << ' ';

	os << endl;

}

int main()
{
	vector<int> pent = { 1,2,3 };
	const string title("Pentagonal Numeric Series");

	if (pen(2, pent))
		display(pent, title, cout);
	if (pen(8, pent))
		display(pent, title);

	return 0;
}
```

**练习2.3** 将练习2.2的Pentagonal数列求值函数拆分为两个函数，其中之一为inline，用来检验元素个数是否合理。如果的确合理，而且尚未被计算，便执行第二个函数，执行实际的求职工作。

你的代码：

```c++
void pen(int size, vector<int>& elems)
{

	for (int ix = elems.size(); ix <= size; ++ix) {
		elems.push_back(ix * (3 * ix - 1) / 2);
	}

}

void display(vector<int>& vec, const string& title, ostream& os = cout) {
	os << '\n' << title << "\n\t";

	for (int ix = 0; ix < vec.size(); ++ix)
		os << vec[ix] << ' ';

	os << endl;

}

inline void is_valid(int size, vector<int>& elems,const string& title)
{
	if (size <= 0 || size > 1024) {
		cerr << "Invalid size: " << size << endl;
	}
	else {
		pen(size, elems);
		display(elems, title);
	}
}



int main()
{
	vector<int> pent = { 1,2,3 };
	const string title("Pentagonal Numeric Series");

	is_valid(8, pent,title);
		
	is_valid(0, pent,title);
	

	return 0;
}
```

书上代码：

```c++
//extern 具有头文件一般的作用，
// 这个地方是提供一个声明，
// 如果该函数是在别的文件中被定义的，
//这个是务必要加进去的。
extern void really_calc_elems(vector<int>&, int);

inline bool calc_elems(vector<int>& vec, int pos)
{
	if (pos <= 0 || pos > 64) {
		cerr << "Invalid position: " << pos << endl;
		return false;
	}
	if (vec.size() < pos)
		really_calc_elems(vec, pos);
	return true;
}

void really_calc_elems(vector<int>& vec, int pos)
{
	for (int ix = vec.size() + 1; ix <= pos; ++ix)
		vec.push_back(ix * (ix * 3 - 1) / 2);
}
```

**练习 2.4** 写一个函数，以局部静态(local static)的vector储存Pentagonal数列元素。此函数返回一个const指针，指向该vector。如果vector的大小小于指定的元素个数，就扩充vector的大小。接下来再实现第二个函数，接受一个位置值，返回该位置上的元素。最后，编写main()测试这些函数。

答案：

```c++
#include <vector>
#include<iostream>

inline bool check_validity(int pos)
{
	return (pos <= 0 || pos > 64) ? false : true;
}

const std::vector<int>*
pentagonal_series(int pos)
{
	static std::vector<int> _elems;
	if (check_validity(pos) && (pos > _elems.size()))
	{
		for (int ix = _elems.size() + 1; ix <= pos; ix++)
			_elems.push_back((ix * (3 * ix - 1) / 2));
	}
		return &_elems;
}

bool pentagonal_elem(int pos, int& elem)
{
	if (!check_validity(pos))
	{
		std::cout << "Sorry. Invalid position: " << pos << std::endl;
		elem = 0;
		return false;
	}
	const std::vector<int>* pent = pentagonal_series(pos);
	elem = (*pent)[pos - 1];
	return true;
}

int main()
{
	int elem;
	if (pentagonal_elem(8, elem))
		std::cout << "element 8 is: " << elem << '\n';
	if (pentagonal_elem(88, elem))
		std::cout << "element 88 is: " << elem << '\n';
	if (pentagonal_elem(12, elem))
		std::cout << "element 12 is: " << elem << '\n';

	return 0;
}

```

**练习 2.5** 实现一个重载的`max()`函数，让它接受以下参数：（a）两个整数，(b)两个浮点数，（c）两个字符串，（d）一个整数vector，(e)一个浮点数vector，（f）一个字符串vector，（g）一个整数数组，以及一个表示数组大小的整数值，（h）一个浮点数数组，以及一个表示数组大小的整数值，（i）一个字符串数组，以及一个表示数组大小的整数值。最后，编写`main()`函数测试这些函数。

```c++
#include <string>
#include<vector>
#include<algorithm>
#include<iostream>

inline int max(int t1, int t2)
{
	return t1 > t2 ? t1 : t2;
}

inline float max(float t1, float t2)
{
	return t1 > t2 ? t1 : t2;
}

inline std::string max(const std::string& t1,const std::string & t2)
{
	return t1 > t2 ? t1 : t2;
}

inline int max(const std::vector<int>& vec)
{
	return(*max_element(vec.begin(), vec.end()));
}

inline float max(const std::vector<float>& vec) {
	return *max_element(vec.begin(), vec.end());
}

inline std::string max(const std::vector<std::string>& vec) {
	return *max_element(vec.begin(), vec.end());
}

inline int max(const int* parray, int size)
{
	return *std::max_element(parray, parray + size);	//必须使用std才可以编译通过？！
}

inline float max(const float* parray, int size)
{
	return *std::max_element(parray, parray + size);	//必须使用std才可以编译通过？！
}

inline std::string max(const std::string* parray, int size)
{
	return *max_element(parray, parray + size);
}

int main()
{
	float farray[] = { 2,5,24.8,18.7,4.1,23.9 };
	std::vector<float>fvec(farray, farray + 5);

	float fmax = max(max(fvec), max(farray, 5));
}
```

**练习 2.6** 以template重新完成练习2.5，并用`main()`函数测试。

```c++
#include <string>
#include<vector>
#include<algorithm>
#include<iostream>

template<typename Type>
inline Type max(Type t1, Type t2)
{
	return t1 > t2 ? t1 : t2;
}

template<typename elemType>
inline elemType max(const std::vector<elemType>& vec)
{
	return *max_element(vec.begin(), vec.end());
}

template<typename arrayType>
inline arrayType max(const arrayType* parray, int size)
{
	return *std::max_element(parray, parray + size);
}

int main()
{
    //完全同上。
    return 0;
}
```

## 第三章 面向对象的编程风格(Object Oriented Programming)

### 3.1 面向对象基本原理

对象由数据和操作两部分组成。数据：性质或状态；操作：函数。类（class）是由各种各样的对象抽象出来的性质集合。类定义了对象，一个对象是一个类。

1.**对象之间传递信息。**信息由发出者产生、为接收者所解释的、并由一定的方法（函数）实现。信息可以改变状态，返回结果。一个面向对象风格的程序就是一些对象通过互相传递信息告诉对方做什么（而不是怎么做）。

2.**每一个对象都有一个接口。**接口（interface）是对象接受信息的方式，它定义于对象所属的类之中。接口的作用：交流与保护。

3.**无法直接接触的隐藏实现。**数据不会直接被操作，而是被保护了起来。只有**通过接口**才可以访问。

面向对象的基本原则是：封装、继承和多态。

#### 3.1.1 封装（Encapsulation）

把数据和处理这些数据的操作封装在一起，数据部分位于内部被隐藏起来。

#### 3.1.2 继承(Inheritance)

继承机制使我们得以将一群相关的类组织起来，并让我们得以**分享其间的共同数据和操作行为**。继承机制定义了父子关系。父类定义所有**子类共通的数据接口（public interface）和私有实现（private implementation）**。通俗地讲，就是子类的操作既来源于父类遗传的行为，也包括自身特有的行为。父类称为基类（basic class），子类被称为派生类（derived class）。基类与派生类之间的关系称为继承体系（inheritance hierarchy）。

![Alt](https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202302081942148.png)

上图就是一个继承的实例，相对于Book，RentalBook、AudioBook、CDIBook就是一个派生类，三个派生类含有父类Book的全部数据接口和自身独特的具体实现。LibMat不代表任何一个馆藏，仅仅是为了我们的设计上的需要而实现，我们称之为抽象基类。

#### 3.1.3 多态（polymorphism）

让基类的pointer或reference透明地指向其任何一个派生类的对象。因此，会有不同的指向情况，对于不同的指向情况，同一个操作会有不同的执行状况。

#### 3.1.4 动态绑定（dynamic binding）

程序执行某一类的操作时，到底应该执行哪一个子类的操作，应该由程序真正运行时决定，而不是固定的。这就是动态绑定。

## 3.2 面向对象程序基础——类

​		在C++中，定义一个类需要创建.h头文件和.cppC++文件。其中头文件中包括**类的声明（declaration）和函数的原型（prototypes），函数的定义即函数体（bodies）则放置在源文件.cpp中。** **注意定义（definition）和声明（declaration）的严重区别！**

### 3.2.1 类的访问限制

​		解析符“::”（resolver）：

```c++
void S::f(){
    ::f(); // 没有解析符f()就会递归！最终导致栈的溢出。加上解析符而没有标注所属类代表这是一个全局的函数。
    ::a++; // 选用全局变量a。
    a--; // 代表对象S中的一个成员变量 
}
```

​		在C++中，对类的成员所有访问权限有**public（任何人都可访问）, private（只有<u>类的成员函数</u>可以访问）, protected（只有所在类和它的子类可以访问）**可以是变量，也可以是函数。

​		**同一个类的不同对象可以相互访问它们各自的成员变量！！**

​		private对成员访问的限制仅仅发生在编译时刻。



### 3.2.2 头文件

​		如果函数或类在头文件中声明，**必须要在函数使用以及定义的地方`#include`**。

![Alt](https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202302111409203.png)

编译器在编译过程中，遇到`#include`的时候会进行编译预处理，将`include`的头文件中的代码插入到#include处。

<center> .cpp--编译预处理指令-->.ii--编译器-->.s--汇编器-->.o




​		在C++中上述的头文件中的代码是错误的，因为头文件中是函数和类的**声明**而非**定义**，所以`int global`这一行是不对的。如果我程序中含有两个.cpp文件，在编译的连接过程中，由于头文件中定义语句的存在，会出现变量的重复定义，实际上是定义的变量重名。解决方法很自然地就是将定义转化为声明。**关键字`extern`就是对全局变量的声明**

```c++
//header file a.h
void f();
extern int global;
```

​		然而，声明仅仅是声明，编译器并没有给global分配内存，即没有定义一个叫`global`的变量。在.cpp文件中，要定义一个global

```C++
#include "a.h"
int global;
void f()
{
    global++;
}
```

当然了，如果程序中没有使用`global`将不会产生任何错误，甚至是没有warning。

​		extern变量、函数的原型、类和结构体的创建都是声明，只有这些声明才被允许放在.h文件中。

​		标准头文件的结构是

```c++
#ifndef HEADER_FLAG
#define HEADER_FLAG
// Type declaration here
// ...

#endif
```

条件编译，如果引用多个头文件，这些被引用的头文件中相互包含，那么没有条件编译会使类声明重复。

​		在写头文件的时候，因当遵循以下的良好习惯：

1. 每个头文件中只放置一个类的声明。
2. 不同源代码文件的前缀相同。
3. 头文件的内容要被`#ifndef #define #endif`环绕起来。

### 3.2.3 变量类型

​		变量可分为**成员变量（field）、函数参数（parameter）、本地变量（local variable）**。函数参数=本地变量，离开了函数，这两种变量都不存在了。成员变量定义在所有函数和构造函数之外的变量，成员变量的生存期是在对象中永远存在，其作用域是类的作用域，在该类的所有函数中都可以直接使用成员变量；本地变量则是只能在相应的函数中使用。成员变量的声明和定义变量的方式是一样的，但是成员变量声明后只是告诉编译器存在着这样的变量，而不能指明这样的变量在哪里 。

```C++
//A.h
class A
{
    public:
    	int i;//对成员变量i的声明而非定义，只是在告诉编译器存在着这样的一个i而不知道具体位置。类永远没有i
    	void f();
};
```

```c++
//A.cpp
#include "A.h"
#include<iostream>
void A::f()
{
    std::cout<<i<<std::endl;//加入这行语句，为了探讨这里的i是否是a.i=10定义的i的值。这里的i是a的i，因为只有a才有i，结果应该是输出10。
    i=20;
    std::cout<<i<<std::endl;//应该是20
}
```

```c++
//main.cpp
#include"A.h"
#include<iostream>
int main()
{
    A a;//这行语句之后，i才真正地出现，出现在类的每一个对象里面。i只存在于每一个具体的对象中。
    a.i=10;
    std::cout<<a.i<<std::endl;//应该输出10。
    a.f();//这个f()函数是属于A的还是a的？？？属于A的！不属于具体的对象。
    std::cout<<a.i<<std::endl;//应该是20。
    return 0;
}
```

​		在类中，成员变量是属于**每个具体的对象的**；函数是属于**整个类的。**因为函数代表的操作是从一些对象中抽象而来的共有的属性。函数是全局的函数，参数是类的指针，这样如果一个程序中含有属于某一类的不同对象，可以通过指针来判断成员变量是属于哪一个对象的。

​		类中也可以定义函数，此时函数为inline函数，定义在类中的函数不需要解析符。

​		C++可以编译C的语法，含有C的标准库。`printf()`和`cout`不要混用。

```C++
//A.cpp
#include<stdio.h>
#include"A.h"
void A::f()
{
    i=20;//具体对象的i！！！同名不同物。
    printf("A::f()--&i=%p",&i);
}
```

```c++
//main.cpp
int main()
{
    A a;
    A aa;
    a.i = 10;
    printf("&a=%p\n",&a);
    printf("&a.i=%p\n",&(a.i));
    a.f();
    aa.i = 100;
    aa.f();
}
```

程序的结果是：

![Alt](https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202302221642468.png)

**a.i和a的地址是一样的，因为对象里面除了i没有其他东西了。**在函数内部得到的地址也是a的地址，A::f的i就是a的i。aa是另一个不同的对象，它的地址，成员变量的地址都不同于a的地址。被调用的函数和调用它的变量有某种联系，所以才会识别出不同对象的不同成员变量“i”。这种联系是*this*指针，所有的函数都有一个隐藏的参数叫this，在c++中是一个关键词。

```c++
//A.cpp
#include<stdio.h>
#include"A.h"
void A::f()
{
    this->i=20;//也可以直接i = 20;
    printf("A::f()--&i=%p",&i);
    printf("this=%p\n", this);
}
```

![Alt](https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202302221641650.png)

这是函数的隐藏参数，你无须主动去设定，它指向调用这个函数的对象，这样，函数就能知道作用于哪个对象的成员变量了。这个也是C语言设计C++这些功能的方式，深入认识C++，**就要去试图想这个功能如何用C去实现。**

​		采用`init()`函数对成员变量初始化。

```c++
class Point{
   public:
    void init(int x, int y);
    void print() const;
    void move(int dx, int dy);
   private:
    int x;
    int y;
};

Point a;
a.init(1, 2);
a.move(2, 2);
a.print();
```

C++不对变量进行自动的初始化，在Visual C++编译器中，会在定义的变量主动填入16进制的0xCC，如果未初始化内存（栈），调试出的程序会出现“屯（0xCCCC）”或“烫（0xCDCD）”这个汉字。

​		以上是实现变量初始化的手动方法，它依赖于程序员的自觉性，在设计程序时，要手动添加初始化的代码。

### 3.2.4 构造函数与析构函数

​		C++提供了constructor函数，中文叫构造函数。**构造函数名与类名相同，并没返回类型。构造函数有参数，可以是确定对象如何创造的、可以是初始化变量、等等。**构造函数**必须放在public的访问限制中**，否则无法进行访问，就无法构造这个类的对象。

```C++
class X{
    int i;
   public:
    X();//构造函数，与类名相同，无返回类型，后面介绍这是Default Constructor
};

X::X(int entry){
    i = entry;
}
void f(){
    X a; // 实际上进行的操作是：a.X();
    // ...
}

X a(12);// 对构造函数的调用，12会传给i
```

​		构造函数是对象被创建的时候需要调用的函数，析构函数是对象被消灭的时候要调用的函数，使用析构函数会把构造函数申请的空间给释放掉。

```c++
class Y{
    int i;
    public:
    	Y(int entry); // constructor
    	~Y(); // destructor
};

Y::Y(int entry){
    i = entry;
}
Y::~Y(){
    // ...
}
```

```c++
//main.cpp
int main()
{
    std::cout<<"before opening bace"<<std::endl;
    {
        Y y(12);
        //...
    }//加入了花括号，则将y的scope限制在了花括号之中。
}
```

上述的y什么时候会被析构呢？在花括号结束之后，y就要被析构。析构之后，变量的空间就要被收回。如果程序中没有析构函数，编译器会自动析构。

### 3.2.5对象的初始化

对于一个函数或者一对花括号构建起的作用域，编译器在运行到**花括号的时候就已经将花括号中的变量分配好了空间**，而构造函数只有运行到了**定义语句**才开始进行变量的初始化。

```c++
void f(int i){
    if(i<10){
        goto jump1;
    }
    X x1; //Constructor called here
    jump1:
    switch(i){
        case 1:
            X x2; //Constructor called here
            break;
        case 2:
            X x3;
            break;
    }
}
```

运行这段代码，当使用`goto`运行到了`Switch`语句之后，构造函数`X x1`就没有被运行。既然没有被运行，而又为`x1`开辟了空间，等到程序将其析构之后就会遇到问题。(报错：控制传输跳过初始化)

各种类型变量的初始化：(注：**在C++中，structure和class是一样的，只有一些十分细微的差别，structure不说明public还是private的时候默认为public；而class默认为private**)

```c++
int a[5] = {1, 2, 3, 4, 5};

int b[6] = 5; //b = {5, 0, 0, 0, 0, 0}

int c[]={1, 2, 3, 4}; //sizeof c/sizeof *c

struct X{int i; float f; char c;};
X x1 = {1, 2.2, 'c'};
X x2[3] = {{1, 1.1, 'a'}, {2, 2.2, 'b'}};

struct Y{float f; int i; Y(int a);};
Y y1[] = {Y(1), Y(2), Y(3)}// structure之中含有了构造函数
```

默认的构造函数：是可以不带参数来调用的构造器。**注：不是Auto Default Constructor，那个是编译期自动给的构造，Default Constructor是自己设计的、不带参数的构造函数**。

```c++
struct Y{
    float f;
    int i;
    Y(int a) // 不是Default Contructor
}
Y y1[] = {Y(1), y(2), Y(3)};
Y y2[2] = {Y(1)}; //错误(活动)	E0289	没有与参数列表匹配的构造函数 "Axx::Axx" 实例、“Axx”没有合适的默认构造函数可用（来自Visual C++）	

```

同样地，在类中定义了一个构造函数，而没有进行类的初始化，同样会报错：类“ XXX”找不到默认的构造函数。

可以用关键字`default`来要求编译器生成构造函数。其中，`=default`既可以和声明一起出现在类的内部（inline），也可以作为定义出现在类的外部。

```C++
class D{
    public:
    D()=default;
}
```

在定义构造函数时，便可以初始化构造函数参数列表：

```c++
class D{
    public:
    D():year(2000),month(1),day(1){};
}
```

### 3.2.6 动态内存分配

在C语言中，可以使用`malloc`函数进行动态内存分配（Dynamic memory allocation），在C++中，使用`malloc`相关的关键字（malloc, realloc, free...）需要调用`malloc.h`头文件。在C++中提供了`new` `delete`运算符实现这个事情。先`new`一个空间，之后再构造函数；先析构，之后再`delete`空间。

`new`常常用于创建一个Dynamic Array（动态数组）：

```c++
int *psome = new int[10]; //运算符new将返回申请内存的首地址。
delete[] psome; //使用delete[]来释放掉。
```

psome所指的位置不只有一个东西，要加[]，此时所有的东西对应的析构都会被调用，此时**与这所有东西对应的析构函数都将会被调用**。如果仅仅是`delete psome;`空间依旧会被收回，只是，只有首地址对应的东西的析构函数被调用。值得说明的是，`new`是C++运行库中的函数，它不会向操作系统要内存，程序运行开始，操作系统就已经分配好了固定的内存。`new`只是在分配好的内存之中再开辟一块内存。

```c++
int* a = new int[10];
a++;
delete[] a;
```

此时，在Visual Studio中，程序会因为触发一个断点而终止运行，原因和`new`的机制有关。在使用`new`申请一块内存时，实际上生成了一张表，记录申请的内存容量和首地址，并将首地址返回给a，如果把a的值改动，`delete`将找不到应当释放的内存，因为在表中，**没有a++的首地址**。

*实验：delete不带[]会怎样*

```c++
// A.h
#include<iostream>
class A{
    private:
    	int i;
   public:
    	A(){i = 0; std::cout<<"\t A::A()"<<std::endl;}
    	~A(){std::cout<<"\t A::~A()"<< "i= "<< i<<std::endl;}
    	void set(int i){this->i = i;} // (int ii){i= ii}
}
// main.cpp
int main()
{
    A* p = new A[10];
    
    for(int i=0; i<10; ++i){
        p[i].set(i);
    }
    
    delete [] p;
    
    return 0;
}
```

运行结果：(含有16-18行)

![](https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202302242109696.png)

运行结果：（不含16-18行）

![](https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202302242113867.png)

`delete`不带`[]`的运行结果：没有结果，程序中断了。

使用delete注意：

1. 不要用`delete`释放一块根本没有申请的内存。
2. 不要释放同一空间两次。
3. 如果使用`new Type []`来申请内存，要使用`delete []`来响应的释放掉**否则程序会出错终止！**
4. **delete一个null指针是安全的，因为它遇到null根本不做事情！**
5. delete应写尽写，在设计大型常运行软件时，不使用delete，会造成内存泄露。

### 3.2.7 友元（Friends）

类可以允许其他**类或者函数**访问它的非公有成员（private），方法是令其他类或者函数成为它的友元。想把一个函数变成友元，只需要在开头加上关键字`friend`即可。

```c++
struct X; //不完整的结构体定义，称为前向声明。为了让第四行的语句编译可以通过。

struct Y{
    void f(X*);
};

struct X{
    private:
    int i;
    public:
    void initialize();
    friend void g(X* x, int i); // Global friend
    friend void Y::f(X*); // Struct member friend
    friend struct Z; // Entire struct is a friend
    friend void h();
};

// .cpp
void X::initialize(){
    i = 0;
}

void g(X* x, int i){
    x -> i = i;
}

void Y::f(X* x){
    x -> i = 47;
}

struct Z{
    private:
    int j;
}
```

友元在运算符重载中经常使用。

注意事项：

1. 声明一个函数或者类是友元，必须要在**请求访问非公有成员的类中声明友元**。
2. 友元函数在类内声明，定义可以在内部或者外部定义。
3. C++不允许将某个类的构造函数、析构函数和虚函数声明为友元函数。
4. 友元关系不具有对称性，只是单方面的允许。
5. 友元关系不具有传递性

**友元类**，当一个类被声明为友元类时，该类可以存取另一个类的所有私有成员。

### 3.2.8 构造函数初始值列表

```c++
using namespace std;

struct A{
    int i;
    int* p;
   public:
    A(){p=0; cout<<"A::A()"<<endl;}
    /*可以将第七行的p以初始化列表的方法赋初始值*/
    A():p(0){cout<<"A::A()"<<endl;}
    
    ~A(){if(p)delete p; cout<<"A::~A()"<<I<<endl;}
    
}
```

```c++
class Point{
    private:
    const float x, y;
    Point(float xa = 0.0, float ya = 0.0)
        : y(ya), x(xa){}		// Initialized list
};
```

初始化列表的进行会早于构造函数的运行。

观察下面的代码，比较构造函数初始化与列表初始化的不同

```c++
Student::Student(string s):name(s){} //初始化
Student::Student(string s){
    name = s; // 先初始化 name，后对name赋值
}
```

结果都是对对象进行了初始化，但是运行的机制不一样。第二种方式因为没有给变量`name`一个初始值，运行赋值语句`name = s;`**之前还是要先对`name`进行初始化，只是用什么值进行初始化没有明确**。

看一个构造函数初始化的例子：

```c++
// b.cpp
class B{
   public:
    	B(int i){}
};

struct A{
    int i;
    B b;
   public:
    A():i(0){b=0};
}

g++ b.cpp

错误:	C2512	“B”: 没有合适的默认构造函数可用	
```

加上B的默认构造函数：

```c++
// b.cpp
class B{
   public:
    	B(int i){}
    	B(){}
};

struct A{
    int i;
    B b;
   public:
    A():i(0){b=0};
}

g++ b.cpp

编译通过！
```

采用初始化列表：

```c++
int main()
{
	class B {
	public:
		B(int i) {}
	};
	struct A {
		int i;
		B b;
	public:
		A() :i(0), b(0) {  }
	};
}
g++ a.cpp
编译通过！
```

​	1.**类的所有成员变量，都要用初始化列表进行初始化**。

​	2.父类的构造函数要放在初始化列表之中。

### 3.2.9 对象的组合（Composition）

软件重用在OOP编程中除了常用的类的继承，还有对象的组合。

![](https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202302251645132.png)

对象的组合就是把不同的对象封装在一个大的对象之中，即，对象之中包含对象。包含对象有两种方式——fully和by reference。顾名思义，fully就是对象真的是在对象之中定义的；by reference是大的对象之中含有小对象的位置（地址）。

**Fully：成员变量是对象本身；By reference：成员变量是另一个对象的地址。**

**对象组合的初始化**

因为组合对象中含有别的对象，因此会有别的类的构造函数，那么在进行初始化的过程中，该如何进行初始化？对象放到新的对象之中还是保持它的封装，初始化还是应该由自己管理。**应当使用列表初始化**。

```c++
SavingsAccount::SavingsAccount(const char* name, const char* address, int cents):m_saver(name, address)
    , m_balance(0, cents){} // Initialized list

void SavingsAccount::print(){
    m_saver.print();
    m_balance.print(); // 处于SavingsAccount类的两个类m_saver和m_balance调用的还是自己类中的操作。
}
```

如果在一个类里面的某些个成员变量是对象，它应该用Initialized list进行初始化。

```c++
savingsAccount::SavingsAccount(const char* name, const char* address, int cents){
    m_saver.set_name(name);
    m_saver.set_address(address);
    m_balance.set_cents(cents);
} // 这样的写法需要默认构造函数
```

## 第四章 面向对象程序设计

### 4.1 继承 （Inheritance）

具有继承关系的类，父类（Parent Class又名基类（Basic Class）、超类（Super Class））的数据、操作、接口（public的method）是共享的，是C++核心的技术。

<img src="https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202302271703046.png" alt="image-20230227170320847" style="zoom:67%;" />

子类（Sub Class，又名派生类（Derive Class）、Child）除了拥有父类的一切操作和数据，还会在此基础上进行扩充，子类是父类的超集，父类是子类的超类。

```c++
class A{
public:
    	A():i(0){cout << "A::A()" < <endl;}
    	~A(){cout << "A::~A()" << endl;}
    	void print(){cout << "A::print()" << i << endl;}
    	void set(int ii){this -> i = ii;}
private:
    	int i;
};

class B : public A{ //表达继承的语法
    
};

int main()
{
    B b;
    b.set(10);
    b.print();
    return 0;
}
```

运行结果：

![image-20230301161217213](https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202303011612416.png)

可以看到，在构造子类b的对象时，其父类的构造函数**被自动调用**！

子类b是否可以直接访问基类的private呢？

```c++
class A{
public:
    	A():i(0){cout << "A::A()" < <endl;}
    	~A(){cout << "A::~A()" << endl;}
    	void print(){cout << "A::print()" << i << endl;}
    	void set(int ii){this -> i = ii;}
private:
    	int i;
};

class B : public A{ 
public:
    void f(){
        i = 30; //直接访问
        print();
    }
};

int main()
{
    B b;
    b.set(10);
    b.print();
    b.f();
    return 0;
}
```

<img src="https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202303011617862.png" alt="image-20230301161733675" style="zoom: 80%;" />

基类中**私有的东西在子类中是存在的。但是没有权限直接访问，只允许通过操作使用**。

```c++
class A{
public:
    	A():i(0){cout << "A::A()" < <endl;}
    	~A(){cout << "A::~A()" << endl;}
    	void print(){cout << "A::print()" << i << endl;}
protected:
    	void set(int ii){this -> i = ii;}
private:
    	int i;
};

class B : public A{ 
public:
    void f(){
        set(20); //子类访问protected，被允许。
        print();
    }
};

int main()
{
    B b;
    b.set(10); // 外部访问protected，被禁止！！！！！！！！！！！！！！！！！！！！！！！！
    b.print();
    b.f();
    return 0;
}
```

<img src="https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202303011623055.png" alt="image-20230301162335876" style="zoom:80%;" />

**protected通常被用于给它的子类访问private的接口**。

**实例** 声明一个雇员类

```c++
class Employee{
public:
    Employee(cost std::string& name, const std::string& ssn);
    
    const std::string& get_name() const;
    void print(std::ostream& out) const;
    void print(std::ostream& out, const std::string& msg) const;
protected: //派生类可以使用这个数据，这不是个聪明的选择
    std::string m_name;
    std::string m_ssn;
}


Employee::Employee(const string& name, const string& ssn): m_name(name), m_ssn(ssn){}
/*函数的overload*/
inline const std::string& Employee::get_name() const
{
    return m_name;
}
inline void Employee::print(std::ostream& out) const{
    out<<m_name<<endl;
    out<<m_ssn<<endl;
}
inline void Employee::print(std::ostream& out, const std::string& msg) const
{
    out<< msg<<endl;
    print(out); //利用已经写好的代码，不要code duplication
}
```

想要新建一个Manager类，在Employee的基础之上

```c++
class Manager : public Employee{
public:
    Manager(const std::string& name, const std::string& ssn, const std::string& title);
    const std::string title_name() const;
    const std::string& get_title() const;
    void print(std::ostream& out) const; /**/
private:
    std::string m_title;
}
```

从前面的例子可知，构造一个子类的对象时，基类的构造函数自动地被调用，然而在这个例子中，父类并没有默认构造函数，那么我在创建一个b的对象时，语句`Manager manager`是否存在问题？

为了简化这个问题，我们采用前一个代码：

```c++
#include<iostream>
using namespace std;
class A {
public:
	A(int ii) : i(ii) { cout << "A::A()" << endl; }
	~A() { cout << "A::~A()" << endl; }
	void print() { cout << "A::f()" << i << endl; }
protected:
	void set(int ii) { i = ii; }
private:
	int i;
};
class B :public A {
public:
    B(){};
	void f() {
		set(20);
		print();
	}
};
int main()
{
	B b;
	b.print();
}
```

B中没有任何构造函数，A也没有默认构造函数

<img src="https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202303031923421.png" alt="image-20230303192311227" style="zoom:80%;" />

这张图很好地表达了父类与子类的关系：子类中**包含了父类的body**，有了父类所有的东西。

<img src="https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202302271703046.png" alt="image-20230227170320847" style="zoom:67%;" />

**初始化子类，父类的一切也要初始化，如何初始化？**在对象的组合中，我们就已经看到了**一个对象的初始化只能有该对象所在的类的构造函数来完成**，类的继承也不例外。所以还要父类的构造参与初始化。所以，我们需要调用父类的构造函数。

```c++
class B :public A {
public:
    B() : A(15) {}; //父类的构造函数只能放置在子类的初始化列表之中！不能放在函数体，因为子类不可以主动去调用父类的构造函数
	void f() {
		set(20);
		print();
	}
};
int main()
{
	B b;
	b.print();
}
```

**初始化的顺序与列表顺序无关，与声明的顺序有关。**

```c++
class B :public A {
public:
    B() : A(15) {cout << "B::B()" << endl;}; 
    ~B(){cout<<"B::~B()"<<endl;} // 看看先构造的B还是先构造A
```

<img src="https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202303031943744.png" alt="image-20230303194311522" style="zoom:80%;" />

**构造顺序、析构顺序完全相反**。

调用父类的函数，要使用类的作用域符::。

如果在子类和父类中定义了名字一样的函数，会怎么样？

```c++
/*同样地，在原来的代码中稍加改动*/
#include<iostream>
using namespace std;
class A {
public:
	A(int ii) :i(ii) { cout << "\tA::A()" << endl; }
	~A() { cout << "\tA::~A()" << endl; }
	void print() { cout << "A::print()" << i << endl; } //print()
	void print(int i) { cout << i; print(); }
protected:
	void set(int ii) { i = ii; }
private:
	int i;
};

class B :public A {
public:
	void print() { cout << "B::print()" << endl; } //print()
	void f() {
		set(20);
	//	i = 30;
		print();
	}

	B() : A(15) { cout << "\tB::B()" << endl; };
	~B() { cout << "\tB::~B()" << endl; }
};
int main()
{
	B b;
	b.print();
	b.print(200); /*ERROR!函数调用中参数过多、B::print()函数不接受一个参数！
}
```

没有与B::print(int)相匹配的函数，称为name hiding，是所有面向对象高级语言中*C++特有的行为*。**如果父类中有重载函数，当子类和父类中出现了重复的函数（名字、参数表相同），那么只剩下子类中的函数，父类中的函数被隐藏**。为什么只有C++这么做？原因来自于另外一个同样是C++特有的特性：子类函数和与它同名的父类函数**没有关系**。其他的OOP语言(Java)如果两个函数同名、同参数表，这叫做Override。要是没有关系，那么所有父类中所有的重载函数都应该没有关系。

子类的对象可以当成父类看待，（学生也是人），多出的东西会被忽略。叫做upcast。

```c++
Manager pete("Pete", "444-55-6666", "bakery");
Employee* ep = &pete; //upcast
Employee& er = pete; //upcast
```

### 4.2 多态(Polymorphism)

<img src="https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202303041449324.png" alt="image-20230304144921695" style="zoom: 50%;" />



```c++
class XYPos{};
class Shape{
public:
    Shape();
    virtual ~shape(); //析构也存在virtual
    virtual void render(); //不同类的render操作些许不同
    void move(const SYPos&);
    virtual void resize();
    
protected:
    XYPos center;
};
```

有了virtual 关键字，子类与父类的同名函数才有了联系。

```c++
class Ellipse : public Shape{
public:
    Ellipse(float maj, float ninr);
    virtual void render(); //不加virtual，render也是virtual，这样写，是为了提高代码的可读性，知道是virtual了就不必再看Shape
protected:
    float major_axis, minor_axis;
};
class Circle : public Ellipse{
public:
    Circle(float radius) : Ellipse(radius, radius){}
    virtual void render();
};

void render(Shape* p){
    p->render();
}
void func(){
    Ellipse ell(10, 20);
    ell.render(); 
    Circle circ(40);
    circ.render();
    render(&ell); //upcast，执行ellipse的render
    render(&circ); //upcast，执行Circle的render
}
```

对于相同的method，在运用到不同的派生类，可能会略有不同，但都是基于基类，这样的现象被称为多态(polymorphism)。在上述代码中，**p是多态的**，p指了什么对象，就变成哪个对象的形态。

**Polymorphism基于upcast，将派生类当成基类来看待；同时基于dynamic binding，程序执行某一类的操作时，到底应该执行哪一个子类的操作，应该由程序真正运行时指针所指对象决定，而不是固定的。这就是动态绑定。**

如何实现多态？采用虚函数。

```c++
#include<iostream>
using namespace std;
class A {
public:
	A() :i(10) {}
	virtual void f() { cout << "A::f()" << i << endl; }
	int i;
};
int main()
{
	A a;
	a.f();
	cout << sizeof(a) << endl;

	int* p = (int*)&a;
	//p++;
	cout << *p << endl;
}
```

结果：

A::f()10
8
8887092

执行`p++`的操作：

A::f()10
8
10

说名a中在i的上面还有东西，是什么呢？是指针。

<img src="https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202303041741209.png" alt="image-20230304174114063" style="zoom: 50%;" />

所有含有virtual的对象中，最开始会自动加上一个隐藏的指针。vptr指向一张表叫做“vtable”，这里面有所有virtual函数的地址。vtable属于这个类的而非具体的对象。不同的对象的这张表相同。

采用虚函数，基类希望派生类对其进行覆盖。当我们使用指针或引用调用虚函数时，该调用将被动态绑定。**根据引用或指针所绑定的对象类型不同，执行基类的版本或者派生类的版本。**所以，对虚函数的调用可能在运行时刻才会被解析。






# C++学习笔记

[toc]

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
int &rval = ival;	//reference（引用），代表一个int对象
```

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

　reference和pointer的用法不太相同，区别在于使用pointer使一定确保指针非零，因为指针可能指向其他奇奇怪怪的对象。

```C++
void display(const vector<int> *vec)
{
    if(! vec){
        cout << "display(): the vector pointer is 0\n";
        return;
    }
    for(int ix = 0; ix < vec->size(); ix++){
        cout << *(vec)[ix] << ' ';
    }
    cout << endl;
}
int main()
{
    ......
}
```

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

### 2.5 声明inline函数

​		模块化、程式化编程一直以来都是编写程序所恪守的原则。所谓模块化，就是将程序以最简单的逻辑设计。每个逻辑节点通常是某种动作功能。这一动作功能为一函数。在之前的实例中，`fibo_elem()`返回一个Fibonacci数列元素，其位置由用户指定。我们将各个小工作分解为独立函数，以求更简化：

```c++
bool is_size_ok(int size)
{
	const int max_size = 1024;
	if (size<0 || size>max_size) {
		cerr << "Requested size is not supported: "
			<< size << "--can't fulfill request.\n";
		return false;
	}
	return true;
}
//计算Fibonacci数列中的size个元素，
//并返回持有这些元素的静态容器的地址
const vector<int>*
fibon_seq(int size)
{
	const int max_size = 1024;
	static vector<int>elems;

	if (!is_size_ok(size))
		return 0;

	for (int ix = elems.size(); ix < size; ix++) {
		if (ix == 0 || ix == 1)
			elems.push_back(1);
		else elems.push_back(elems[ix - 1] + elems[ix - 2]);
	}
	return &elems;
}

//返回Fibonacci数列中位置为pos的元素
//如果程序无法支持该位置上的元素，便返回false
bool fibon_elem(int pos, int& elem)
{
	const vector<int>* pseq = fibon_seq(pos);

	if (!pseq) {
		elem = 0; return false;
	}
	elem = (*pseq)[pos - 1];
	return true;
}
```

这样的设计，使得每一个函数只实现一个功能。但是有些时候，编译过程中编译的函数过多会降低程序运行的性能。C++提供了inline（内联函数）解决了该问题。

​		将函数声明为inline，表示编译器在每个函数调用点上，将函数的内容展开。面对一个inline函数，编译器可将该函数的调用操作改为以**一份代码副本**代替，其结果是把三个函数写入fibo_elem()内，**但依然维持三个独立的运算单元**。

```c++
//现在fibon_elem()成了inline函数
inline bool fibon_elem(int pos, int &elem)
{
    //....
}
```

​		在函数返回类型之前加上关键字inline，可以解决一些频繁调用的函数大量消耗栈空间（栈内存）的问题。引入inline函数是为了替代**C中表达式的宏定义**。

<center> #define	ExpressionName(Var1, Var2) ((Var1+Var2)*(var1-Var2))

  

这种宏定义效率很高，但是仅仅是符号表中的简单替换，不能享受C++编译器严格检查的好处，它的返回值也不能被强制转换为合适的类型。inline函数克服了这一缺陷。因此实际上设置成inline的函数，就相当于宏定义中的符号替换。

​		一般而言，最适合声明为inline的函数，和`fibon_elem()`以及`is_size_ok()`一样：**体积小，常被调用，所从事的计算并不复杂**。

​		值得一提的是。将函数指定为inline，只是对编译器提出的一种要求。编译器是否执行这样的要求，须视编译器而定。inline函数的定义，常常被放在头文件中。**关键字inline必须与函数定义放在一起才能使函数成为内联函数，仅仅将inline函数放在函数声明前不起任何作用。**

### 2.6 提供重载函数

​		假设我们已经写好了一个通用的函数`display_message()`用来显示我们需要显示的信息。我们可能需要显示一串数字，也可能是一段字符，也可能是转义字符`\t\n`。但是我们定义函数的时候，参数列表已经唯一地指定。这样过于僵硬，我们想要让其灵活地实现显示各种数据类型的对象。怎么办？通常，一个函数的定义全部由定义该函数的所有性质决定：函数名，返回值类型，参数列表，函数体。由集合的外延公理，性质有一个不一样，那么整个函数就是不一样的函数，例如

```C++
void display_message(char ch);
void display_message(const string&);
void display_message(const string&, int);
void display_message(int, const string&);
void display_message(const string&, int, int);
```

实际上这是五个不同的函数，但是具有相同的函数名，我们称其为**函数的重载**。后面讲到模板函数会讲到实现它的具体方法。我们要讨论重载函数的正确使用方法。

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

### 2.7 定义并使用模板函数

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

### 2.8 函数指针带来更大的弹性

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

### 2.9 设定头文件

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

## 第四章 泛型编程风格(Generic Programming)

​		STL主要由两种组件构成：一是容器(container)，二是操作这些容器的泛型算法，包括find(), sort(), replace(), merge()等。容器可分为顺序性容器，主要进行迭代操作，和关联性容器，可以快速查找容器中的元素值。

![Alt](https://gitee.com/you-xu2003/markdown-pic/raw/master/img/202302081943362.png)

​		map是一对对**key/value**组合。key表示用于查找，value用来表示我们要存储或取出的数据。set仅含有key。我们对set进行查找，为的是**判断某值是否存在于其中**。如果我们想要建立一组索引表，用来记录出现于新闻、故事中的字眼，我们会将一些“中性字眼”比如*the*、*an*、*but*排除掉。用set就可以实现这个功能。



​		


















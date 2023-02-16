#include<bits/stdc++.h> 
using namespace std;

struct HuffmanNode 
{ 
    char data;	            // 待编码的符号
    double weight;	            // 符号出现的频率 
    int parent, lchild, rchild;       // 父结点、左, 右孩子结点的位置
};

class HuffmanTree
{ 
    //vector<HuffmanNode> hufftree;  // 树中所有结点的存储空间
    int n;			           // 叶子结点数
    void SelectSmall(int &least,int &less,int i);
public:
	vector<HuffmanNode> hufftree;
    HuffmanTree(vector<HuffmanNode> &leafs);
    vector<int> GetCode( int i );
    string Decode(vector<int> &source);
//    string Encode()
};

HuffmanTree::HuffmanTree(vector<HuffmanNode> &leafs)
{
	n = leafs.size();
	hufftree.resize(2*n-1);
	for(int i=0;i<n;i++)
	{
		hufftree[i].data = leafs[i].data;
		hufftree[i].weight = leafs[i].weight;
		hufftree[i].parent = hufftree[i].lchild 
						   = hufftree[i].rchild 
						   = -1;
	}
	for(int i=n;i<2*n-1;i++)
	{
		int least,less;
		SelectSmall(least,less,i);
		hufftree[least].parent = hufftree[less].parent = i;
		hufftree[i].parent = -1;
		hufftree[i].lchild = least;
		hufftree[i].rchild = less;
		hufftree[i].weight = hufftree[least].weight 
							+ hufftree[less].weight;
	}
}
//--------------------------
void HuffmanTree::SelectSmall(int &least,int &less,int i)
{
	for (int j = 0; j < i; j++)
        if (hufftree[j].parent == -1)
        {
            least = j;
            break;
        }
    for (int j = 0; j < i; j++)
        if (hufftree[j].parent == -1 && hufftree[least].weight > hufftree[j].weight)
            least = j;
    for (int j = 0; j < i; j++)
        if (hufftree[j].parent == -1&&j!=least)
        {
            less = j;
            break;
        }
    for (int j = 0; j < i; j++)
        if (hufftree[j].parent == -1 && hufftree[less].weight > hufftree[j].weight&&j != least)
            less = j;
}
//--------------------------
vector<int> HuffmanTree::GetCode( int i )
{
	vector<int>code;
	int p = i;
	int parent = hufftree[i].parent;
	while(parent!= -1)
	{
		if(hufftree[parent].lchild == p)
			code.insert(code.begin(),0);
		else
			code.insert(code.begin(),1);
		p = parent;
		parent = hufftree[parent].parent;
		//cout<<code[i];
	}
	return code;
 } 
//--------------------------
string HuffmanTree::Decode(vector<int> &source)
{
	string target ="";
	int root = hufftree.size() -1;
	int p = root;
	for(int i=0;i<source.size();i++)
	{
		if(source[i] == 0)
			p = hufftree[p].lchild;
		else
			p = hufftree[p].rchild;
		if(hufftree[p].lchild == -1 
			&& hufftree[p].rchild == -1)
		{
			target = target + hufftree[p].data;
			p = root;	
		}
	 }
	 return target;
}


 void print(vector<HuffmanNode> hT,int n)
 {
     cout << "index weight parent lChild rChild" << endl;
     cout << left;    // 左对齐输出 
     for (int i = 0; i < n; ++i) 
     {
        cout << setw(5) << i << " ";
        cout << setw(6) << hT[i].weight << " ";
        cout << setw(6) << hT[i].parent << " ";
        cout << setw(6) << hT[i].lchild << " ";
        cout << setw(6) << hT[i].rchild << endl;
    }
 }

#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

struct node
{
	int val;

	node *left, *right;

	node() {}
	node(node *l, node *r, int v)
	{
		left = l;
		right = r;
		val = v;
	}
};

int arr[MAXN];

void build(node *n, int low, int high)
{
	if(low == high)
	{
		n->val = arr[low];
		return;
	}

	int mid = (low + high) / 2;

	n->left = new node(NULL, NULL, 0);
	n->right = new node(NULL, NULL, 0);

	build(n->left, low, mid);
	build(n->right, mid + 1, high);

	n->val = n->left->val * n->right->val;
}

void upgrade(node *n, int low, int high, int idx, int v)
{
	if(idx < low || high < idx || low > high) return;
	if(low == high)
	{
		n->val = v;
		return;
	}

	int mid = (low + high) / 2;

	upgrade(n->left, low, mid, idx, v);
	upgrade(n->right, mid + 1, high, idx, v);

	n->val = n->left->val * n->right->val;
}

int query(node *n, int low, int high, int A, int B)
{
	if(B < low || A > high || low > high) return 1;
	if(A <= low && high <= B) return n->val;

	int mid = (low + high) / 2;

	return query(n->left, low, mid, A, B) * query(n->right, mid + 1, high, A, B);
}

int main(int argc, char** argv)
{
	int N, Q, A, B;
	char O;

	while(cin >> N >> Q)
	{
		node *root = new node(NULL, NULL, 0);

		for(int i = 1; i <= N; i++)
		{
			cin >> arr[i];
			if(arr[i] > 0)
				arr[i] = 1;
			if(arr[i] < 0)
				arr[i] = -1;
		}

		build(root, 1, N);

		for(int i = 0; i < Q; i++)
		{
			cin >> O >> A >> B;

			if(O == 'C')
				upgrade(root, 1, N, A, (B > 0 ? 1 : (B < 0 ? -1 : 0)));
			else
			{
				int r = query(root, 1, N, A, B);
				cout << (r > 0 ? '+' : (r < 0 ? '-' : '0'));
			}
		}

		cout << endl;
	}

	return 0;
}

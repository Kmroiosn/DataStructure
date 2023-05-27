#include <iostream>
#include <string>
#include <functional>
#include <ranges>
#include <vector>
#include <deque>

template <typename Ty>
struct BinaryNode
{
	Ty* m_Data;

public:
	BinaryNode *left, *right;

	template <typename... Args>
	BinaryNode(Args&&... args)
		: left(nullptr), right(nullptr)
	{
		if constexpr (sizeof...(args) > 0) { m_Data = new Ty(args...); }
		else { m_Data = nullptr; }
	}

	template <Ty NullptrValue>
	static BinaryNode* PreorderBuild(std::deque<Ty> data) noexcept
	{	// 不允许根结点为空值
		if (!data.empty() && data.front() != NullptrValue)
		{
			BinaryNode* root = new BinaryNode(data.front());
			data.pop_front();

			root->left = PreorderCreateNode<NullptrValue>(data);
			root->right = PreorderCreateNode<NullptrValue>(data);

			return root;
		}
		return nullptr;
	}

	template <Ty NullptrValue>
	static BinaryNode* PreorderCreateNode(std::deque<Ty>& data) noexcept
	{
		if (!data.empty())
		{
			if (data.front() == NullptrValue)
			{
				data.pop_front();
				return nullptr;
			}
			auto* node = new BinaryNode(data.front());
			data.pop_front();

			node->left = PreorderCreateNode<NullptrValue>(data);
			node->right = PreorderCreateNode<NullptrValue>(data);

			return node;
		}
		return nullptr;
	}


	Ty* data() noexcept { return m_Data; }

	template <bool IgnoreNullptr = true>
	void PreorderTravelRecursively(const std::function<void(Ty*)>& func)
	{
		func(m_Data);
		if constexpr (IgnoreNullptr)
		{
			if (left) left->PreorderTravelRecursively<IgnoreNullptr>(func);
			if (right) right->PreorderTravelRecursively<IgnoreNullptr>(func);
		}
		else
		{
			if (left) left->PreorderTravelRecursively<IgnoreNullptr>(func);
			else func(nullptr);
			if (right) right->PreorderTravelRecursively<IgnoreNullptr>(func);
			else func(nullptr);
		}
	}

	template <bool IgnoreNullptr = true>
	void InorderTravelRecursively(const std::function<void(Ty*)>& func)
	{
		if constexpr (IgnoreNullptr) { if (left) left->InorderTravelRecursively<IgnoreNullptr>(func); }
		else
		{
			if (left) left->InorderTravelRecursively<IgnoreNullptr>(func);
			else func(nullptr);
		}

		func(m_Data);

		if constexpr (IgnoreNullptr) { if (right) right->InorderTravelRecursively<IgnoreNullptr>(func); }
		else
		{
			if (right) right->InorderTravelRecursively<IgnoreNullptr>(func);
			else func(nullptr);
		}
	}

	template <bool IgnoreNullptr = true>
	void PostorderTravelRecursively(const std::function<void(Ty*)>& func)
	{
		if constexpr (IgnoreNullptr)
		{
			if (left) left->PostorderTravelRecursively<IgnoreNullptr>(func);
			if (right) right->PostorderTravelRecursively<IgnoreNullptr>(func);
		}
		else
		{
			if (left) left->PostorderTravelRecursively<IgnoreNullptr>(func);
			else func(nullptr);
			if (right) right->PostorderTravelRecursively<IgnoreNullptr>(func);
			else func(nullptr);
		}
		func(m_Data);
	}
};

template<typename Ty, Ty NullptrValue>
auto printNode = []
{
	return [](auto* data)
	{
		using namespace std;
		if (data)
			cout << *data << endl;
		else
			cout << NullptrValue << endl;
	};
};


int main()
{
	using Node = BinaryNode<char>;

	Node* root = new Node('A');
	root->left = new Node('B');

	root->left->left = new Node('C');
	root->left->right = new Node('D');

	root->left->right->left = new Node('E');
	root->left->right->right = new Node('F');

	root->left->right->left->right = new Node('G');

	root->PreorderTravelRecursively<false>(printNode<char, '^'>());

	std::cout << "Next root: " << std::endl;

	// 两个树的数据是相同的
	Node* newRoot = Node::PreorderBuild<'^'>(
		{'A', 'B', 'C', '^', '^', 'D', 'E', '^', 'G', '^', '^', 'F', '^', '^', '^'});
	newRoot->PreorderTravelRecursively<false>(printNode<char, '^'>());

	return 0;
}

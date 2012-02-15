/*
 *        M   M  M  MMM                     UUU
 *        M   M M M M M                     U    U   U
 *   WWWW M M M M M MMM                     U   UUU UUU WWWW
 *   WWWW MM MM MMM MM                      U    U   U  WWWW
 *   WW   M   M M M M M       HH HH         UUU           WW
 *   WW                       HH HH                       WW
 *   WW MM  MM   MM   HH      HH HH      HH MMMMMM MMMMMM WW
 *   WW MM  MM   MM   HH      HH HH      HH MMMMMM MMMMMM WW
 *   WW MM  MM MM  MM HHHH  HHHH HHHH  HHHH MM     MM  MM WW
 *   WW MM  MM MM  MM HHHH  HHHH HHHH  HHHH MM     MM  MM WW
 * WW   MMMMMM MM  MM HH  HH  HH HH  HH  HH MMMM   MMMMMM   WW
 * WW   MMMMMM MM  MM HH  HH  HH HH  HH  HH MMMM   MMMMMM   WW
 *   WW MM  MM MMMMMM HH      HH HH      HH MM     MMMM   WW
 *   WW MM  MM MMMMMM HH      HH HH      HH MM     MMMM   WW
 *   WW MM  MM MM  MM HH      HH HH      HH MMMMMM MM  MM WW
 *   WW MM  MM MM  MM HH      HH HH      HH MMMMMM MM  MM WW
 *   WW                       HH HH                       WW
 *   WW                       HH HH                       WW
 *   WWWW                     HH HH                     WWWW
 *   WWWW                     HH HH                     WWWW
 *                            HH HH
 *                            HH HH NNN NNN NNN NNN NNN NNN NNN
 *                            HH HH N N N N N N   N N   N    N
 *                            HH HH NNN NNN N N N N NN  N    N
 *                                  N   NN  N N N N N   N    N
 *                                N N   N N NNN NNN NNN NNN  N
 *
 * TreeExpressionInterpreterVisitor.tpp
 *
 *  Created on: Jun 02, 2011
 *      Author: Felipe Wannmacher
 *	   License: LGPL - http://http://www.gnu.org/licenses/lgpl.html
 */

#ifdef __WarHammer_datastructure_util_EXPRESSIONINTERPRETERSTRINGPARSER_HPP__

#include <cctype>
#include <cstdlib>
#include <stack>
#include "../../exception/Exception.hpp"
#include "../../util/exception/ExpressionInterpreterException.hpp"

template<typename Content, typename TreeNodeSubclass>
WarHammer::datastructure::util::TreeExpressionInterpreterVisitor<Content, TreeNodeSubclass>::TreeExpressionInterpreterVisitor(WarHammer::datastructure::Tree<Content, TreeNodeSubclass>* tree)
{
	this->_tree = tree;
}

template<typename Content, typename TreeNodeSubclass>
WarHammer::datastructure::util::TreeExpressionInterpreterVisitor<Content, TreeNodeSubclass>::~TreeExpressionInterpreterVisitor(void)
{
}

template<typename Content, typename TreeNodeSubclass>
void WarHammer::datastructure::util::TreeExpressionInterpreterVisitor<Content, TreeNodeSubclass>::_parseExpressionNode(WarHammer::datastructure::KTreeNode<WarHammer::util::String>* currentNode, std::vector<Content>& result)
{
	std::stack<WarHammer::datastructure::KTreeNode<WarHammer::util::String>*> path;
	std::vector<TreeNodeSubclass*> treeNodes,
								   treeChildNodes;

	do
	{
		path.push(currentNode);
		currentNode = currentNode->getParent();
	}while(currentNode);

	while(!path.empty())
	{
		if(path.top()->getContent() == "r")
			treeNodes.push_back(this->_tree->getRootNode());
		else
		{
			treeChildNodes.clear();

			if(path.top()->getContent().contains("-"))
			{
				std::vector<WarHammer::util::String> tokens = path.top()->getContent().split("-");

				unsigned int begin = atoi(tokens[0].getCString()),
							 end = atoi(tokens[1].getCString());

				for(unsigned int i = 0; i < treeNodes.size(); ++i)
					for(unsigned int j = begin; j <= end && j < treeNodes[i]->getChildren().size(); ++j)
						treeChildNodes.push_back(treeNodes[i]->getChildren()[j]);
			}
			else if(path.top()->getContent() == "*")
				for(unsigned int i = 0; i < treeNodes.size(); ++i)
					for(unsigned int j = 0; j < treeNodes[i]->getChildren().size(); ++j)
						treeChildNodes.push_back(treeNodes[i]->getChildren()[j]);
			else
			{
				unsigned int index = atoi(path.top()->getContent().getCString());

				for(unsigned int i = 0; i < treeNodes.size(); ++i)
					if(treeNodes[i]->hasChildren() && treeNodes[i]->getChildren().size() > index)
						treeChildNodes.push_back(treeNodes[i]->getChildren()[index]);
			}

			treeNodes = treeChildNodes;
		}

		path.pop();
	}

	for(unsigned int i = 0; i < treeNodes.size(); ++i)
		result.push_back(treeNodes[i]->getContent());
}

template<typename Content, typename TreeNodeSubclass>
bool WarHammer::datastructure::util::TreeExpressionInterpreterVisitor<Content, TreeNodeSubclass>::_isExpressionValid(WarHammer::util::String expression)
{
	if(expression[0] != 'r')
		return false;

	bool valid = true;
	std::stack<WarHammer::datastructure::KTreeNode<WarHammer::util::String>*> openNodes;
	WarHammer::datastructure::KTreeNode<WarHammer::util::String>* rootNode = new WarHammer::datastructure::KTreeNode<WarHammer::util::String>("r");
	WarHammer::datastructure::KTree<WarHammer::util::String> syntaxTree;
	syntaxTree.setRootNode(rootNode);

	if(expression.length() > 1)
		openNodes.push(rootNode);

	//WarHammer::util::String nodeContent = "";
	WarHammer::datastructure::KTreeNode<WarHammer::util::String>* node = NULL;

	for(unsigned int i = 1; i < expression.length() && valid; ++i)
		if(openNodes.empty())
			valid = false;
		else
			switch(expression[i])
			{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				if(expression[i - 1] != '{' && expression[i - 1] != '-' && expression[i - 1] != ':')
					valid = false;

				for(++i; isdigit(expression[i]) && i < expression.length() - 1; ++i);

				if(expression[i] != '}' && expression[i] != '{' && expression[i] != ':' && expression[i] != '-')
					valid = false;
				else
					--i;

				break;
			case '*':
				if(expression[i - 1] != '{')
					valid = false;

				if(expression[i + 1] != '}' && expression[i + 1] != '{')
					valid = false;

				break;
			case '-':
				break;
			case ':':
				node = new WarHammer::datastructure::KTreeNode<WarHammer::util::String>("");
				openNodes.top()->getParent()->addChild(node);
				openNodes.push(node);
				break;
			case '{':
				node = new WarHammer::datastructure::KTreeNode<WarHammer::util::String>("");
				openNodes.top()->addChild(node);
				openNodes.push(node);
				break;
			case '}':
				if(openNodes.size() <= 1)
					valid = false;
				else
				{
					node = openNodes.top()->getParent();

					while(openNodes.top()->getParent() == node)
						openNodes.pop();
				}

				break;
			default:
				valid = false;
				break;
			}

	if(openNodes.size() > 1)
		valid = false;

	WarHammer::datastructure::KTree<WarHammer::util::String>::Iterator iterator = syntaxTree.getIterator();

	for(iterator.goesLast(); iterator.hasPrevious(); --iterator)
		delete iterator.getCurrentNode();

	return valid;
}

template<typename Content, typename TreeNodeSubclass>
std::vector<Content> WarHammer::datastructure::util::TreeExpressionInterpreterVisitor<Content, TreeNodeSubclass>::_parseExpression(WarHammer::util::String expression)
{
	std::vector<Content> result;
	std::stack<WarHammer::datastructure::KTreeNode<WarHammer::util::String>*> openNodes;
	WarHammer::datastructure::KTreeNode<WarHammer::util::String>* rootNode = new WarHammer::datastructure::KTreeNode<WarHammer::util::String>("r");
	WarHammer::datastructure::KTree<WarHammer::util::String> expressionTree;
	expressionTree.setRootNode(rootNode);

	if(expression.length() > 1)
		openNodes.push(rootNode);

	WarHammer::util::String nodeContent = "";
	WarHammer::datastructure::KTreeNode<WarHammer::util::String>* node = NULL;

	for(unsigned int i = 1; i < expression.length(); ++i)
		switch(expression[i])
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			nodeContent = expression[i];

			for(++i; isdigit(expression[i]) && i < expression.length() - 1; ++i)
				nodeContent += expression[i];

			--i;
			node = openNodes.top();
			node->setContent(node->getContent() + nodeContent);
			break;
		case '*':
			openNodes.top()->setContent(expression[i]);
			break;
		case '-':
			node = openNodes.top();
			node->setContent(node->getContent() + expression[i]);
			break;
		case ':':
			node = new WarHammer::datastructure::KTreeNode<WarHammer::util::String>("");
			openNodes.top()->getParent()->addChild(node);
			openNodes.push(node);
			break;
		case '{':
			node = new WarHammer::datastructure::KTreeNode<WarHammer::util::String>("");
			openNodes.top()->addChild(node);
			openNodes.push(node);
			break;
		case '}':
			node = openNodes.top()->getParent();

			while(openNodes.top()->getParent() == node)
				openNodes.pop();

			break;
		}

	WarHammer::datastructure::KTree<WarHammer::util::String>::Iterator iterator = expressionTree.getIterator();

	for(iterator.goesFirst(); iterator.hasNext(); ++iterator)
		if(!iterator.getCurrentNode()->hasChildren())
			this->_parseExpressionNode(iterator.getCurrentNode(), result);

	for(iterator.goesLast(); iterator.hasPrevious(); --iterator)
		delete iterator.getCurrentNode();

	return result;
}

template<typename Content, typename TreeNodeSubclass>
void WarHammer::datastructure::util::TreeExpressionInterpreterVisitor<Content, TreeNodeSubclass>::visit(WarHammer::util::ExpressionInterpreterSyntaxValidator<std::vector<Content> >* validator)
{
	if(!this->_isExpressionValid(validator->getExpression()))
		ThrowNewException(WarHammer::util::exception::ExpressionInterpreterException::INVALID_EXPRESSION, this);
}

template<typename Content, typename TreeNodeSubclass>
void WarHammer::datastructure::util::TreeExpressionInterpreterVisitor<Content, TreeNodeSubclass>::visit(WarHammer::util::ExpressionInterpreterStringParser<std::vector<Content> >* parser)
{
	parser->setExpressionResult(this->_parseExpression(parser->getExpression()));
}

#endif

// A node of the tree
class Node {
  public:
    int key;
    Node* left;
    Node* right;
    Node* parent;

    // Constructor
    Node(int key, Node* parent=nullptr, Node* left=nullptr, Node* right=nullptr) {
        this->key = key;
        this->parent = parent;
        this->left = left;
        this->right = right;
        if (left) left->parent = this;
        if (right) right->parent = this;
    }
};

// Binary tree
class Tree {
  public:
    // Pointer to root of the tree; nullptr if the tree is empty.
    Node* root;

    Tree(Node* root=nullptr) {
        this->root = root;
    }

    // Rotate the given `node` up. Perform a single rotation of the edge
    // between the node and its parent, choosing left or right rotation
    // appropriately.
    void rotate(Node* node) {
        if (node->parent) {
            if (node->parent->left == node) {
                if (node->right) node->right->parent = node->parent;
                node->parent->left = node->right;
                node->right = node->parent;
            } else {
                if (node->left) node->left->parent = node->parent;
                node->parent->right = node->left;
                node->left = node->parent;
            }
            if (node->parent->parent) {
                if (node->parent->parent->left == node->parent)
                    node->parent->parent->left = node;
                else
                    node->parent->parent->right = node;
            } else {
                root = node;
            }

            Node* original_parent = node->parent;
            node->parent = node->parent->parent;
            original_parent->parent = node;
        }
    }

    // Look up the given key in the tree, returning the
    // the node with the requested key or nullptr.
    Node* lookup(int key) {
        // TODO: Utilize splay suitably.
        Node* node = root;
		Node* lastNode = nullptr;
        while (node) {
            if (node->key == key) {
				splay(node);
                return node;
            }
			if (key < node->key) {
				lastNode = node;
				node = node->left;
			}

			else {

				lastNode = node;
                node = node->right;
			}
        }
		splay(lastNode);
        return nullptr;
    }

    // Insert a key into the tree.
    // If the key is already present, nothing happens.
    void insert(int key) {
        // TODO: Utilize splay suitably.
        if (!root) {
            root = new Node(key);
            return;
        }

        Node* node = root;
        while (node->key != key) {
            if (key < node->key) {
                if (!node->left)
                    node->left = new Node(key, node);
                node = node->left;
            } else {
                if (!node->right)
                    node->right = new Node(key, node);
                node = node->right;
            }
        }
		splay(node);
    }

    // Delete given key from the tree.
    // It the key is not present, do nothing.
    void remove(int key) {
        // TODO: Utilize splay suitably.
        Node* node = root;
		Node* lastNode = nullptr;
        while (node && node->key != key) {
			if (key < node->key) {
				lastNode = node;
				node = node->left;
			}
			else {
				lastNode = node;
                node = node->right;
			}
        }



        if (node) {
            if (node->left && node->right) {//má oba podstromy
                Node* replacement = node->right;//replacement má bıt levı node pravého podstromu
                while (replacement->left)
                    replacement = replacement->left;
                node->key = replacement->key;//node key bude key náhrady
				lastNode = replacement->parent;
                node = replacement;//node je najednou náhrada
            }

            Node* replacement = node->left ? node->left : node->right; //pokud má node leveho syna tak repl je levy jinak je pravy (nechybi podminka elese ?? )
            if (node->parent) { //nejsme root 
                if (node->parent->left == node) node->parent->left = replacement; //nahradime odkaz na node v otci spravnym 
                else node->parent->right = replacement; //replacementem
            } else {//jsme root tak nahradime root replacementem
                root = replacement;
            }
            if (replacement) //pokud je replacement nenull
                replacement->parent = node->parent; //dame replacementuv parent noduv parent
            delete node;
        }
			splay(lastNode);
		
    }

    // Splay the given node.
    // If a single rotation needs to be performed, perform it as the last rotation
    // (i.e., to move the splayed node to the root of the tree).
    void splay(Node* node) {
        // TODO: Implement
		//we decide if we should do single or double rotation
		
		while (node->parent) {
			if (node->parent->parent)
			{
				rotate(node);
				rotate(node);
			}
			else
			{
				rotate(node);
			}
		}
    }

    // Destructor to free all allocated memory.
    ~Tree() {
        Node* node = root;
        while (node) {
            Node* next;
            if (node->left) {
                next = node->left;
                node->left = nullptr;
            } else if (node->right) {
                next = node->right;
                node->right = nullptr;
            } else {
                next = node->parent;
                delete node;
            }
            node = next;
        }
    }
};

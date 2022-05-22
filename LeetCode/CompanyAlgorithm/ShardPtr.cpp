/**
* 智能指针shared_ptr代码实现：
*/

template<typename T>
class ShardPtr{
public:
	// 构造函数
	ShardPtr(T* ptr = nullptr): _ptr(ptr), _pcount(new int(1)){}

	// 拷贝构造函数
	ShardPtr(const ShardPtr& orgPtr): _ptr(orgPtr._ptr), _pcount(orgPtr._pcount) {
		(*_pcount)++;
	};

	// 重载 赋值操作符重载 =
	ShardPtr<T>& operator=(const ShardPtr& orgPtr) {
		if (this != &orgPtr) {
			--(*(this->_pcount));
			if (*(this->_pcount) == 0) {
				// 引用计数为0，需要释放对象
				delete this->ptr;
				delete this->_pcount;
			}
			_ptr = orgPtr._ptr;
			_pcount = orgPtr._pcount;
			*(_pcount)++;
		}

		return *this;
	}

	// 重载解引用 操作符 *  解引用或者指针
	T& operator*() {
		return *(this->_ptr);
	}

	T* operator->() {
		return this->_ptr;
	}

	// 重载 析构函数
	~ShardPtr() {
		--(*(this->_pcount));
		if(*(this->_pcount) == 0) {
			delete _ptr;
			_ptr = nullptr;
			delete _pcount;
			_pcount = nullptr;
		}
	}

private:
	T* _ptr;
	int* _pcount; // 引用计数的指针
};
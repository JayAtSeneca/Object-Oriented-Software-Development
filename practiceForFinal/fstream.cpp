// Smart Pointer
 // SmartPtr.h

 template <typename T>
 class SmartPtr {
     T* p { nullptr };
   public:
     explicit SmartPtr(T* ptr) : p(ptr) { } ; 
     SmartPtr(const SmartPtr&) = delete;
     SmartPtr& operator=(const SmartPtr&) = delete; 
     SmartPtr(SmartPtr&& s) noexcept {
         p = s.p;
         s.p = nullptr;
     }
     SmartPtr& operator=(SmartPtr&& s) noexcept { 
         if (this != &s) {
             delete p;
             p = s.p;
             s.p = nullptr;
         }
         return *this;
     }
     ~SmartPtr() {
         delete p;
     }
     T& operator*() {
         return *p;
     }
     T* operator->() {
         return p;
     }
 };
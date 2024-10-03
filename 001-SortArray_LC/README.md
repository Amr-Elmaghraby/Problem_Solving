---

# C++ Access Specifiers and Related Keywords

In C++, **access specifiers** and other related keywords define how members of a class (variables and functions) can be accessed and controlled, both inside and outside of the class. This document provides an overview of key access control keywords and concepts.

## 1. **Public** (`public`)
Members declared as `public` can be accessed from **anywhere** in the program where the object is visible. This includes other classes, derived classes, and external code.

**Example:**
```cpp
class Base {
public:
    int publicVar; // Can be accessed from anywhere
};

class Derived : public Base {
    void func() {
        publicVar = 10; // Accessing public member from Base
    }
};

int main() {
    Base b;
    b.publicVar = 20; // Can be accessed from outside the class
}
```

## 2. **Protected** (`protected`)
Members declared as `protected` can be accessed within the **same class** and in **derived classes**. They are still hidden from non-derived classes or external code.

**Example:**
```cpp
class Base {
protected:
    int protectedVar; // Can be accessed in Derived class
};

class Derived : public Base {
    void func() {
        protectedVar = 10; // Accessing protected member from Base
    }
};
```

## 3. **Private** (`private`)
Members declared as `private` are accessible only within the **same class**. They cannot be accessed or modified by derived classes or any other external class.

**Example:**
```cpp
class Base {
private:
    int privateVar; // Only Base class can access privateVar
};

class Derived : public Base {
    void func() {
        // privateVar is not accessible here
    }
};
```

---

## 4. **Friend** (`friend`)
The `friend` keyword allows another **class** or **function** to access the private and protected members of a class. `Friend` classes or functions are exceptions to usual access rules.

**Example:**
```cpp
class MyClass {
private:
    int secret = 42;

public:
    friend void AccessSecret(MyClass &obj); // Declaring a friend function
};

void AccessSecret(MyClass &obj) {
    std::cout << "Secret: " << obj.secret << std::endl; // Accessing private member
}

int main() {
    MyClass obj;
    AccessSecret(obj); // Works because AccessSecret is a friend
}
```

---

## 5. **Virtual** (`virtual`)
The `virtual` keyword enables **runtime polymorphism**, allowing functions to be overridden in derived classes. When a function is marked as `virtual`, the derived class can override it, and the correct function is called based on the type of the object at runtime.

**Example:**
```cpp
class Base {
public:
    virtual void show() { // Virtual function
        std::cout << "Base show" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override { // Overrides the base class show
        std::cout << "Derived show" << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    b->show(); // Calls Derived's show because of virtual function
}
```

---

## 6. **Final** (`final`)
The `final` keyword is used to prevent further **inheritance** of a class or **overriding** of a virtual function in derived classes.

- **Applied to a class**: No other class can derive from it.
- **Applied to a virtual function**: No other derived class can override that function.

**Example:**
```cpp
class Base {
public:
    virtual void show() final { // Cannot be overridden in Derived
        std::cout << "Base show" << std::endl;
    }
};

class FinalClass final { }; // No class can inherit from FinalClass

// Error: Cannot inherit from a class marked final
// class AnotherClass : public FinalClass { };
```

---

## 7. **Override** (`override`)
The `override` keyword is used in a derived class to explicitly indicate that a function is intended to **override** a base class virtual function. It helps catch errors when the function signature doesn’t match, preventing accidental function hiding.

**Example:**
```cpp
class Base {
public:
    virtual void show() { std::cout << "Base show" << std::endl; }
};

class Derived : public Base {
public:
    void show() override { // Explicitly overrides the base class show
        std::cout << "Derived show" << std::endl;
    }
};
```

---

## 8. **Mutable** (`mutable`)
The `mutable` keyword allows a member of a class to be modified even if the object is declared as `const`. Normally, declaring an object as `const` prevents modification of any member, but `mutable` allows certain members to be modified despite the `const` qualifier.

**Example:**
```cpp
class MyClass {
public:
    mutable int counter = 0;

    void Increment() const {
        counter++; // Allowed because counter is mutable
    }
};

int main() {
    const MyClass obj;
    obj.Increment(); // Even though obj is const, counter can be modified
}
```

---

## 9. **Default** (`= default`)
The `= default` keyword allows you to explicitly instruct the compiler to generate the **default implementation** for special member functions (like constructors or assignment operators).

**Example:**
```cpp
class MyClass {
public:
    MyClass() = default; // Use the default constructor
};
```

---

## 10. **Delete** (`= delete`)
The `= delete` keyword prevents a function from being used. This is useful when you want to disable certain operations, such as the copy constructor or assignment operator.

**Example:**
```cpp
class MyClass {
public:
    MyClass(const MyClass &) = delete; // Disable copy constructor
};

int main() {
    MyClass obj1;
    // MyClass obj2 = obj1; // Error: copy constructor is deleted
}
```

---

## 11. **Explicit** (`explicit`)
The `explicit` keyword prevents implicit conversions or constructor calls. It is typically used in single-argument constructors to avoid unintended type conversions.

**Example:**
```cpp
class MyClass {
public:
    explicit MyClass(int x) {
        std::cout << "Constructor called with " << x << std::endl;
    }
};

int main() {
    MyClass obj1(10); // OK
    // MyClass obj2 = 20; // Error: explicit prevents implicit conversion
}
```

---

### Summary of Access Specifiers and Keywords:
- **public**: Accessible from anywhere.
- **protected**: Accessible within the class and its derived classes.
- **private**: Accessible only within the class.
- **friend**: Grants access to private/protected members to specific functions or classes.
- **virtual**: Enables runtime polymorphism and allows overriding in derived classes.
- **final**: Prevents inheritance or overriding.
- **override**: Ensures a function overrides a base class virtual function.
- **mutable**: Allows modification of a member in a `const` object.
- **default**: Requests the default implementation of a special member function.
- **delete**: Disables a function to prevent its use.
- **explicit**: Prevents implicit conversions using constructors.

---

This README covers essential C++ access specifiers and keywords for controlling member visibility, inheritance, and object behavior. Proper use of these features helps in designing robust and maintainable C++ programs.

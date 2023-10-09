# qt cxx
## some qt cxx feature verification demos and test case;
***
QMetaObject::invokeMethod和QObject::connect是Qt框架中用于处理信号与槽的两个重要函数，它们有以下区别：
#### 功能不同：
```
QMetaObject::invokeMethod用于调用对象的方法（包括槽函数），可以在任何地方使用，不仅限于信号与槽的连接。它允许你以动态方式调用对象的方法，可以指定方法的名称、参数和调用方式。
QObject::connect用于建立信号与槽的连接，当信号触发时，槽函数会被自动调用。它是Qt中实现事件驱动编程的重要机制。
参数不同：

QMetaObject::invokeMethod的参数包括目标对象、方法名称、调用方式（例如，直接调用、QueuedConnection等）以及方法的参数。
QObject::connect的参数包括发送信号的对象、信号的名称、接收信号的对象、槽函数的指针或lambda表达式，以及连接类型（例如，直接连接、自动连接等）。
```
#### 使用场景不同：
```
QMetaObject::invokeMethod适用于需要在特定时间点以动态方式调用对象方法的情况。例如，当你需要在后台线程中调用主线程的方法时，可以使用invokeMethod函数。
QObject::connect适用于建立对象之间的信号与槽连接，用于处理对象之间的事件和通信。通过连接信号与槽，可以实现对象之间的松耦合和消息传递。
```
总的来说，QMetaObject::invokeMethod用于动态地调用对象的方法，而QObject::connect用于建立信号与槽之间的连接。它们在功能、参数和使用场景上有明显的区别，但都是Qt框架中非常有用的工具，用于实现灵活的事件处理和对象间的通信。
***


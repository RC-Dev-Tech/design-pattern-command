/*
 * Design Pattern - Command 命令模式
 * 
 * 在這個範例中，Command是命令的抽象類別，定義了命令對象需要實現的方法，包括執行和撤銷命令的方法。
 * ConcreteCommand是具體的命令實現類，實現了Command介面，並且包含一個Receiver的引用，用於調用具體的操作或方法。
 * Receiver是執行具體操作的類別。Invoker是調用命令對象的類別，並且持有命令對象的引用。
 * Client創建並配置具體命令對象，並將其與具體接收者關聯起來。可以通過調用Invoker的方法來執行命令。
 * 透過這樣的設計，Client可以方便地創建和管理不同的命令，Invoker負責調度執行和撤銷命令的操作，
 * Command提供了對具體操作的封裝，Receiver負責實際執行操作。
 * 這樣的架構使得命令的執行和撤銷可以靈活地組合和控制。
 */

#include <iostream>
#include <vector>

/*
 * Receiver.
*/
class Receiver {
public:
    void Action() {
        std::cout << "Receiver: Performing action" << std::endl;
    }

    void UndoAction() {
        std::cout << "Receiver: Undoing action" << std::endl;
    }
};

/*
 * Command.
*/
class Command {
public:
    virtual void Execute() = 0;
    virtual void Undo() = 0;
};

/*
 * ConcreteCommand.
*/
class ConcreteCommand : public Command {
private:
    Receiver* receiver;

public:
    ConcreteCommand(Receiver* receiver) : receiver(receiver) {}

    void Execute() override {
        receiver->Action();
    }

    void Undo() override {
        receiver->UndoAction();
    }
};

/*
 * Invoker.
*/
class Invoker {
private:
    std::vector<Command*> commands;

public:
    void AddCommand(Command* command) {
        commands.push_back(command);
    }

    void ExecuteCommands() {
        for (Command* command : commands) {
            command->Execute();
        }
    }

    void UndoCommands() {
        for (int i = commands.size() - 1; i >= 0; i--) {
            commands[i]->Undo();
        }
    }
};

/*
 * Client.
*/
int main() {
    Receiver receiver;
    ConcreteCommand command1(&receiver);
    ConcreteCommand command2(&receiver);

    Invoker invoker;
    invoker.AddCommand(&command1);
    invoker.AddCommand(&command2);

    invoker.ExecuteCommands();
    invoker.UndoCommands();

    return 0;
}

# ![](https://drive.google.com/uc?id=10INx5_pkhMcYRdx_OO4rXNXxcsvPtBYq) Command 命令模式
> ##### 理論請自行找，網路上有很多相關的文章，這邊只關注於範例實作的部分.

---

<!--ts-->
## 目錄
* [目的](#目的)
* [使用時機](#使用時機)
* [URL結構圖](#url結構圖)
* [實作成員](#實作成員)
* [實作範例](#實作範例)
* [參考資料](#參考資料)
<!--te-->

---

## 目的
將一個操作封裝為一個對象，從而使你可以用不同的操作對象參數化客戶端，同時支持撤銷操作。

---

## 使用時機
當你需要將一個操作或命令封裝為一個對象並支持其撤銷時，可以使用 Command 設計模式。<br>
這將使得操作具有更大的彈性和可維護性，並且可以很容易地實現功能如撤銷、重做、日誌記錄等。

---

## URL結構圖
![](https://drive.google.com/uc?id=1fgrFXzxl3EL8KyPKIOf-Kaqt-QzjldGq)
> 圖片來源：[Refactoring.Guru - Command](https://refactoring.guru/design-patterns/command)

---

## 實作成員
* Command
  * 命令的抽象類別或介面，定義了命令對象需要實現的方法，包括執行和撤銷命令的方法。
* ConcreteCommand
  * 實現 Command 介面，並且包含一個 Receiver 的引用，用於調用具體的操作或方法。
* Receiver
  * 執行具體操作的類別或介面。
* Invoker
  * 調用命令對象的類別，並且持有命令對象的引用。
* Client
  * 創建並配置具體命令對象，並將其與具體接收者關聯起來。可以通過調用 Invoker 的方法來執行命令。

---

## 實作範例:
- [Example](https://github.com/RC-Dev-Tech/design-pattern-command/blob/main/C%2B%2B/main.cpp) - Command Pattern (C++) 

---

## 參考資料
* [Wiki - Command Pattern](https://en.wikipedia.org/wiki/Command_pattern) <br>
* [Refactoring.Guru - Command](https://refactoring.guru/design-patterns/command) <br>

---

<!--ts-->
#### [目錄 ↩](#目錄)
<!--te-->
---

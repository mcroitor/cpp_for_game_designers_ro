# Programare bazată pe evenimente

- [Programare bazată pe evenimente](#programare-bazată-pe-evenimente)
  - [Noțiuni de bază](#noțiuni-de-bază)
  - [Arhitectura aplicației](#arhitectura-aplicației)
  - [Exemple](#exemple)
  - [Biblioteci și framework-uri](#biblioteci-și-framework-uri)
  - [Bibliografia](#bibliografia)

## Noțiuni de bază

Un sistem informațional poate fi considerat ca un obiect care are un anumit stare și comportament. Starea unui sistem informațional este determinat de un set de valori care descriu sistemul respectiv (atribute). Comportamentul sistemului este determinat de un set de acțiuni care pot fi efectuate asupra sistemului.

Modificarea stării unui obiect se numește __eveniment__. În urma evenimentului se creează un mesaj care conține informații despre evenimentul care a avut loc și care poate fi procesat de sistem. Deseori evenimentul și mesajul creat în urma evenimentului sunt folosite interschimbabil.

Evenimentele generate de factori externi se numesc __evenimente externe__, iar evenimentele generate de sistem se numesc __evenimente interne__.

Sistem informațional reacționează la evenimente, procesându-le cu metode speciale numite __procesori de evenimente__.

__Programarea bazată pe evenimente__ (sau __programarea orientată pe evenimente__, en. _event-driven programming_) este o paradigmă de programare în care accentul principal se pune pe procesarea evenimentelor. Programa scrisă conform principiilor programării bazate pe evenimente reprezintă un set de procesori de evenimente care sunt apelați la apariția unor evenimente specifice.

Programarea bazată pe evenimente presupune împărțirea aplicației în părți independente, fiecare dintre ele fiind responsabilă pentru procesarea unui anumit eveniment (sau un set de evenimente). Aceste părți ale sistemului informațional pot funcționa în fire de execuție separate și pot interacționa între ele prin evenimente.

## Arhitectura aplicației

Programarea bazată pe evenimente se utilizează pe scară largă în interfețele grafice, deoarece permite reacționarea la acțiunile utilizatorului. În interfața grafică, evenimentele pot fi legate de diferite elemente ale interfeței, cum ar fi butoane, câmp de introducere, meniuri etc. Fiecare element al interfeței poate genera evenimente, la care trebuie să reacționeze procesorii de evenimente corespunzători.

Programare bazată pe evenimente permite separarea logicii aplicației în părți independente, fiecare dintre ele fiind responsabilă pentru procesarea unui anumit eveniment. Acest lucru facilitează dezvoltarea și întreținerea programului, deoarece fiecare procesor de eveniment poate fi implementat sub formă de funcție sau metodă separată.

Arhitectura generică a aplicației bazate pe evenimente constă din următoarele componente:

- __Eveniment__ (en. _event_) — semnal care indică faptul că ceva s-a întâmplat în sistem. Evenimentele pot fi generate de diferiți factori, cum ar fi utilizatorul, dispozitivele hardware sau alte programe.

În cel mai simplu caz, evenimentul poate fi reprezentat ca o enumerare (enum) care conține toate tipurile de evenimente posibile. De exemplu, pentru interfața grafică, putem defini următoarele tipuri de evenimente:

```cpp
enum class EventType {
    NoEvent,
    ButtonClick,
    MouseMove,
    KeyPress
};
```

Un tip de eveniment mai complex conține date adiționale, de exemplu, despre obiectul care a generat evenimentul.

- __Sursa de eveniment__ (en. _event source_) — obiect care generează evenimente. Sursa de eveniment poate fi reprezentată de un element al interfeței grafice (de exemplu, buton, câmp de introducere) sau de altă parte a programului (de exemplu, socket de rețea, descriptor de fișier).
- __Coada de evenimente__ (en. _event queue_) — structură de date care stochează evenimentele în așteptare. Coada de evenimente permite separarea procesului de generare a evenimentelor de procesul de procesare a evenimentelor.

Coada de evenimente poate fi implementată sub formă de coadă FIFO (First-In-First-Out) în care evenimentele sunt adăugate la sfârșitul cozii și extrase de la începutul cozii.

```cpp
class EventQueue {
    std::deque<EventType> events;
public:
    void Push(const EventType& event) {
        events.push_back(event);
    }

    EventType Pop() {
        if (events.size() == 0) {
            return EventType::NoEvent;
        }
        
        EventType event = events.front();
        events.pop_front();
        return event;
    }
};
```

- __Procesor de eveniment__ (en. _event processor_, _event handler_) — funcție sau metodă care procesează un anumit tip de eveniment. Procesorul de evenimente primește evenimentul și efectuează acțiunile necesare în funcție de tipul evenimentului.

De obicei se definește o interfață pentru procesorul de evenimente, care conține o metodă pentru procesarea evenimentului. Fiecare procesor de evenimente implementează această interfață și definește metoda de procesare a evenimentului.

```cpp
struct EventHandler {
    virtual void operator()(const EventType& event) = 0;
};
```

Altfel procesoare de eveniment pot fi implementate ca metode ale clasei, în acest caz obiectul clasei trebuie să verifice periodic coada de evenimente și să apeleze procesorul de evenimente corespunzător, destinat obiectului respectiv.

- __Dispecer de evenimente__ (en. _event dispatcher_) — componentă a programului care generează evenimente și le adaugă în coada de evenimente. Dispecerul de evenimente este responsabil pentru asocierea surselor de evenimente cu procesorii de evenimente corespunzători.

Cea mai simplă implementare a dispecerului de evenimente se realizează ca o hartă (map) care asociază tipul de eveniment cu procesorul de eveniment corespunzător. Totodată, dispecerul de evenimente poate fi implementat ca o un `switch`.

```cpp
void DispatchEvent(const EventType& event) {
    switch (event) {
        case EventType::ButtonClick:
            buttonClickHandler(event);
            break;
        case EventType::MouseMove:
            mouseMoveHandler(event);
            break;
        case EventType::KeyPress:
            keyPressHandler(event);
            break;
    }
}
```

- __Ciclu de evenimente__ (en. _event loop_) — este o buclă care extrage evenimente din coada de evenimente și le trimite la procesare procesorilor de evenimente corespunzători. Ciclul de evenimente este responsabil pentru procesarea evenimentelor în ordinea în care acestea au fost generate.

De obicei ciclul de evenimente este implementat ca o buclă infinită care extrage evenimente din coada de evenimente și le trimite la procesare procesorilor de evenimente corespunzători (apelând dispecerul de evenimente).

```cpp
void EventLoop() {
    while (true) {
        EventType event = eventQueue.Pop();
        DispatchEvent(event);
    }
}
```

## Exemple

Ca exemplu, considerăm un sistem informațional în care trăiește un motan virtual. Motanul virtual poate genera următoarele evenimente:

- __este flămând__ — motanul este flămând și vrea să mănânce.
- __vrea să fie mângâiat__ — motanul vrea să fie mângâiat și să se joace.
- __este sătul__ — motanul s-a săturat și vrea să doarmă.

Utilizatorul poate interacționa cu motanul virtual, generând următoarele evenimente:

- __a hrăni__ — utilizatorul hrănește motanul.
- __a mângâia__ — utilizatorul mângâie motanul.
- __a ieși din sistem__ — utilizatorul iese din sistem.

```cpp
enum class EventType {
    CatHungry,
    CatWantsToPlay,
    CatSleepy,
    FeedCat,
    PetCat,
    SystemExit
};
```

Evenimentele sunt generate de motanul virtual și utilizatorul și sunt adăugate în coada de evenimente. Sistem de procesare a evenimentelor selectează evenimentele din coadă și le trimite la procesare procesorilor de evenimente corespunzători.

În acest caz procesorii de evenimente sunt reprezentate de clase care implementează interfața `EventHandler`.

```cpp
struct EventHandler {
    virtual void operator()(const EventType& event) = 0;
};

struct CatHungryHandler : public EventHandler {
    void operator()(const EventType& event) override { /* prelucrarea evenimentului */ }
};

struct CatWantsToPlayHandler : public EventHandler {
    void operator()(const EventType& event) override { /* prelucrarea evenimentului */ }
};

struct CatSleepyHandler : public EventHandler {
    void operator()(const EventType& event) override { /* prelucrarea evenimentului */ }
};

struct FeedCatHandler : public EventHandler {
    void operator()(const EventType& event) override { /* prelucrarea evenimentului */ }
};

struct PetCatHandler : public EventHandler {
    void operator()(const EventType& event) override { /* prelucrarea evenimentului */ }
};

struct SystemExitHandler : public EventHandler {
    void operator()(const EventType& event) override { exit(0); }
};
```

Uneori dispecerul de evenimente este implementat ca o hartă (map) care asociază tipul de eveniment cu procesorul de eveniment corespunzător:

```cpp
std::map<EventType, std::shared_ptr<EventHandler>> eventHandlers = {
    {EventType::CatHungry, std::make_shared<CatHungryHandler>()},
    {EventType::CatWantsToPlay, std::make_shared<CatWantsToPlayHandler>()},
    {EventType::CatSleepy, std::make_shared<CatSleepyHandler>()},
    {EventType::FeedCat, std::make_shared<FeedCatHandler>()},
    {EventType::PetCat, std::make_shared<PetCatHandler>()},
    {EventType::SystemExit, std::make_shared<SystemExitHandler>()}
};
```

Deja cunoscutul ciclu de evenimente extrage evenimente din coada de evenimente și le trimite la procesare procesorilor de evenimente corespunzători:

```cpp
void EventLoop() {
    while (true) {
        EventType event = eventQueue.Pop();
        (*eventHandlers[event.type])(event.type);
    }
}
```

Important de menționat că obiectele programului nu trebuie să interacționeze direct între ele. În schimb, ele trebuie să genereze evenimente și să le transmită pentru procesare procesorilor de evenimente corespunzători. Acest lucru permite reducerea cuplării între componentele programului și ușurința extinderii programului.

## Biblioteci și framework-uri

Există multe biblioteci și framework-uri care facilitează dezvoltarea programelor scrise cu programare bazată pe evenimente. Unele dintre cele mai populare biblioteci și framework-uri pentru dezvoltarea interfețelor grafice sunt:

- __WinAPI__ este un set de funcții C pentru dezvoltarea aplicațiilor Windows cu interfață grafică.
- __MFC__ (Microsoft Foundation Classes) este un framework pentru dezvoltarea aplicațiilor Windows cu interfață grafică. Prezintă un înveliș peste WinAPI.
- __Qt__ este un framework pentru dezvoltarea aplicațiilor grafice, cross-platform.
- __GTK__ (GIMP Toolkit) este o bibliotecă pentru dezvoltarea aplicațiilor grafice, vine din Linux, dar este disponibil și pentru alte platforme.
- __wxWidgets__ este o bibliotecă pentru dezvoltarea aplicațiilor grafice.
- __FLTK__ (Fast Light Toolkit) este o bibliotecă pentru dezvoltarea aplicațiilor grafice.

Comunicarea cu interfața grafică în aceste biblioteci se realizează prin programare bazată pe evenimente. Fiecare element al interfeței grafice (de exemplu, buton, câmp de introducere) generează evenimente la care se pot atașa procesori de evenimente corespunzători.

## Bibliografia

1. [_Programare orientată eveniment_, Wikipedia](https://ro.wikipedia.org/wiki/Programare_orientată_eveniment)
2. Fowler М. _Analysis Patterns: Reusable Object Models._ Addison-Wesley. (1996)
3. Gamma E., Helm R., Johnson R., Vlissides J. _Design Patterns: Elements of Reusable Object-Oriented Software._ Addison-Wesley. (1994)
4. [_Windows API_, Microsoft](https://docs.microsoft.com/en-us/windows/win32/apiindex/windows-api-list)
5. [_MFC_, Microsoft](https://docs.microsoft.com/en-us/cpp/mfc/mfc-desktop-applications)
6. [_Qt_, Qt Project](https://www.qt.io/)
7. [_GTK_, GTK](https://www.gtk.org/)
8. [_wxWidgets_, wxWidgets](https://www.wxwidgets.org/)
9. [_FLTK_, FLTK](https://www.fltk.org/)

# Programare orientată pe evenimente

- [Programare orientată pe evenimente](#programare-orientată-pe-evenimente)
  - [Noțiuni de bază](#noțiuni-de-bază)
  - [Arhitectura aplicației](#arhitectura-aplicației)
  - [Exemplu](#exemplu)
  - [Biblioteci și framework-uri](#biblioteci-și-framework-uri)
  - [Bibliografie](#bibliografie)

## Noțiuni de bază

Un sistem informațional poate fi privit ca un obiect care are stare și comportament. Starea sistemului este determinată de un set de valori (atribute) care îl descriu. Comportamentul sistemului este definit de acțiunile ce pot fi efectuate asupra acestuia.

Schimbarea stării unui obiect se numește __eveniment__. În urma unui eveniment se generează un mesaj care conține informații despre evenimentul produs și care poate fi procesat de sistem. Adesea, termenii "eveniment" și "mesaj" sunt folosiți ca sinonime.

Evenimentele inițiate de factori externi se numesc __evenimente externe__, iar cele inițiate de sistem — __evenimente interne__.

Sistemul reacționează la mesajele despre evenimente prin metode speciale numite __handler-e de evenimente__ (en. _event handler_).

__Programarea orientată pe evenimente__ (sau __event-driven programming__) este o paradigmă de programare în care accentul cade pe tratarea evenimentelor. O aplicație scrisă în acest stil este compusă dintr-un set de handler-e de evenimente care sunt apelate la apariția anumitor evenimente.

Programarea orientată pe evenimente presupune împărțirea aplicației în componente independente, fiecare responsabilă de tratarea unui anumit eveniment. Aceste componente pot rula în fire de execuție diferite și pot comunica între ele prin evenimente.

Acest model simplifică dezvoltarea și mentenanța aplicației, deoarece fiecare handler de eveniment poate fi implementat ca o funcție sau metodă separată.

## Arhitectura aplicației

Programarea orientată pe evenimente este larg folosită în interfețele grafice, deoarece permite reacția la acțiunile utilizatorului. Într-o interfață grafică, evenimentele pot fi asociate cu diverse elemente (butoane, câmpuri de text, meniuri etc.), fiecare generând evenimente la care trebuie să reacționeze handler-ele corespunzătoare.

Acest model permite separarea logicii aplicației în componente independente, fiecare responsabilă de tratarea unui anumit eveniment. Astfel, dezvoltarea și mentenanța devin mai simple.

Arhitectura de bază a unei aplicații orientate pe evenimente include următoarele componente:

- __Eveniment__ (en. _event_) — un mesaj semnal care este transmis sistemului și poate fi procesat. Evenimentul conține informații despre tipul său și date suplimentare necesare procesării.

Cel mai simplu mod de a defini evenimentele este folosirea unui enum pentru toate tipurile posibile. De exemplu, pentru o interfață grafică:

```cpp
enum class EventType {
    NoEvent,
    ButtonClick,
    MouseMove,
    KeyPress
};

struct Event {
    EventType type;
    // date suplimentare
};
```

Evenimentele mai complexe pot conține date suplimentare, de exemplu, despre obiectul care a generat evenimentul.

- __Sursă de eveniment__ (en. _event source_) — obiectul care generează evenimente. Poate fi un element de interfață (buton, câmp de text) sau o altă componentă (socket de rețea, descriptor de fișier).
- __Coada de evenimente__ (en. _event queue_) — structură de date unde sunt stocate evenimentele ce așteaptă procesare. Coada permite separarea generării de evenimente de procesarea lor.

O implementare simplă a cozii de evenimente este o coadă FIFO (First-In-First-Out):

```cpp
class EventQueue {
    std::deque<Event> events;
public:
    void Push(const Event& event) {
        events.push_back(event);
    }

    Event Pop() {
        if(events.empty()) {
            return Event{EventType::NoEvent};
        }
        Event event = events.front();
        events.pop_front();
        return event;
    }
};
```

- __Handler de eveniment__ (en. _event handler_) — funcția sau metoda apelată la apariția unui anumit eveniment. Handler-ul execută acțiunile necesare ca răspuns la eveniment.

De obicei se definește o interfață pentru handler-ul de eveniment:

```cpp
struct EventHandler {
    virtual void operator()(const Event& event) = 0;
    virtual ~EventHandler() = default;
};
```

Handler-ele pot fi și metode de clasă; în acest caz, obiectul trebuie să verifice periodic coada de evenimente și să apeleze handler-ul potrivit.

- __Dispatcher de evenimente__ (en. _event dispatcher_) — componenta care generează evenimente și le adaugă în coadă, asociind sursele de evenimente cu handler-ele potrivite.

O implementare simplă a dispatcher-ului poate folosi o mapare între tipuri de evenimente și handler-ele lor sau un switch:

```cpp
EventHandler buttonClickHandler;
EventHandler mouseMoveHandler;
EventHandler keyPressHandler;

void DispatchEvent(const Event& event) {
    switch (event.type) {
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

- __Bucla de evenimente__ (en. _event loop_) — ciclul principal al aplicației, care extrage evenimentele din coadă și le transmite handler-elor potrivite.

De obicei, bucla de evenimente este un ciclu infinit care poate fi oprit la închiderea aplicației:

```cpp
EventQueue eventQueue;

void EventLoop() {
    while (true) {
        Event event = eventQueue.Pop();
        DispatchEvent(event);
    }
}
```

## Exemplu

Să considerăm un sistem cu o pisică virtuală. Pisica poate genera următoarele evenimente:

- __îi este foame__ — pisica vrea să mănânce;
- __vrea să fie mângâiată__ — pisica vrea atenție și joacă;
- __s-a săturat__ — pisica vrea să doarmă.

Utilizatorul poate genera următoarele evenimente:

- __hrănește pisica__ — utilizatorul hrănește pisica;
- __mângâie pisica__ — utilizatorul mângâie pisica;
- __ieșire din sistem__ — utilizatorul închide aplicația.

Evenimentele sunt generate de pisică și de utilizator și sunt adăugate în coada de evenimente. Sistemul de procesare extrage evenimentele și le transmite handler-elor potrivite.

```cpp
enum class EventType {
    CatHungry,
    CatWantsToPlay,
    CatSleepy,
    FeedCat,
    PetCat,
    SystemExit
};

struct Event {
    EventType type;
    // date suplimentare
};
```

Handler-ele pot fi implementate astfel:

```cpp
struct EventHandler {
    virtual void operator()(const Event& event) = 0;
    virtual ~EventHandler() = default;
};

struct CatHungryHandler : public EventHandler {
    void operator()(const Event& event) override { /* tratarea evenimentului */ }
};

struct CatWantsToPlayHandler : public EventHandler {
    void operator()(const Event& event) override { /* tratarea evenimentului */ }
};

struct CatSleepyHandler : public EventHandler {
    void operator()(const Event& event) override { /* tratarea evenimentului */ }
};

struct FeedCatHandler : public EventHandler {
    void operator()(const Event& event) override { /* tratarea evenimentului */ }
};

struct PetCatHandler : public EventHandler {
    void operator()(const Event& event) override { /* tratarea evenimentului */ }
};

struct SystemExitHandler : public EventHandler {
    void operator()(const Event& event) override { exit(0); }
};
```

Fără un destructor virtual, la ștergerea prin `std::shared_ptr<EventHandler>` pot apărea scurgeri de memorie dacă clasa derivată alocă resurse.

Dispatcher-ul de evenimente poate fi implementat ca o mapare între tipuri de evenimente și handler-ele lor:

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

Bucla de evenimente extrage evenimentele și le transmite handler-elor:

```cpp
void EventLoop() {
    while (true) {
        Event event = eventQueue.Pop();
        (*eventHandlers[event.type])(event);
    }
}
```

Este important ca obiectele din program să nu interacționeze direct între ele, ci să genereze evenimente și să le transmită handler-elor potrivite. Astfel, se reduce gradul de cuplare între componente și se facilitează extinderea aplicației.

## Biblioteci și framework-uri

Există numeroase biblioteci și framework-uri care simplifică dezvoltarea aplicațiilor bazate pe evenimente. Dintre cele mai populare pentru interfețe grafice:

- __WinAPI__ — set de funcții pentru dezvoltarea aplicațiilor Windows (doar pentru Windows).
- __MFC__ — bibliotecă pentru interfețe grafice în C++ (doar pentru Windows).
- __Qt__ — framework cross-platform pentru interfețe grafice în C++.
- __GTK__ — bibliotecă pentru interfețe grafice în C.
- __wxWidgets__ — bibliotecă cross-platform pentru interfețe grafice în C++.
- __FLTK__ — bibliotecă cross-platform pentru interfețe grafice în C++.

Interacțiunea cu interfața grafică în aceste biblioteci se realizează prin programare orientată pe evenimente. Fiecare element (buton, câmp de text etc.) generează evenimente la care se poate reacționa prin definirea handler-elor corespunzătoare.

## Bibliografie

1. [Programare orientată pe evenimente, Wikipedia](https://ro.wikipedia.org/wiki/Programare_orientat%C4%83_pe_evenimente)
2. Fowler M. _Patterns of Enterprise Application Architecture._ Addison-Wesley. (2002)
3. Gamma E., Helm R., Johnson R., Vlissides J. _Design Patterns: Elements of Reusable Object-Oriented Software._ Addison-Wesley. (1994)
4. [Windows API, Microsoft](https://docs.microsoft.com/en-us/windows/win32/apiindex/windows-api-list)
5. [MFC, Microsoft](https://docs.microsoft.com/en-us/cpp/mfc/mfc-desktop-applications)
6. [Qt, Qt Project](https://www.qt.io/)
7. [GTK, GTK](https://www.gtk.org/)
8. [wxWidgets, wxWidgets](https://www.wxwidgets.org/)
9. [FLTK, FLTK](https://www.fltk.org/)

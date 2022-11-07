# TIMERLIB
Creazione di una libreria per la gestione di un timer per Arduino

# UTILIZZO

#### Start timer con delay
```c++
void start(uint32_t Delay);
```
#### Stop timer
```c++
void stop();
```
#### Restart timer con opzionalmente un nuovo delay
```c++
void restart(uint32_t NewDelay);
```
#### Ritorna lo stato del timer
```c++
bool isRunning();
```
#### Controlla se il timer è scaduto e nel caso lo fa ripartire con un nuovo delay
```c++
bool isOver(bool Restart, uint32_t NewDelay);
```
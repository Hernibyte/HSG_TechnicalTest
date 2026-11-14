# HSG_TechnicalTest

## Diseño y decisiones

Empecé con una implementación básica de un PlayerCharacter. La idea es crear un "UBaseCharacter" que herede de "UCharacter" para tener una clase base modificable en común entre el jugador y un posible IACharacter, para después crear el "UPlayerCharacter" del jugador usando como base dicha "UBaseCharacter". En caso de que se necesite realizar implementaciones que afecten tanto al jugador como a los NPC's puede usarse "UBaseCharacter".

Por el lado del PlayerController es la misma lógica, primero crear un "UBaseController" para tener una clase de tipo Controller en común entre el jugador y un posible npc, para a posterior crear el "UPlayerController".

Los inputs del jugador se crean de la manera estándar usando "UEnhancedInputComponent", asignando InputActions con su respectivo TriggerEvent.

- Los sistemas se implementan en Actor Components para disminuir la carga de funcionalidades que podría llegar a tener una sola clase si se implementa todo en el mismo sitio, dejando la clase principal limpia y además permitiendo facilitar una posible modificación futura.

Cree el "UInteractionComponent" que contiene la implementación de interacciones del player, en este caso la interacción con el Spawner.

- Me decidí a usar interfaces para desacoplar las interacciones entre clases lo más posible, la idea es justamente evitar que una clase dependa de otra que pueda contener muchas funcionalidades, de este modo se abstrae la funcionalidad especifica que uno necesita a la hora de comunicar dos clases entre sí y además en caso de necesitarlo dicha interfaz puede ser usada en muchas otras clases tanto como se desee. Cabe destacar que este tipo de interfaces son algo propio de Unreal, y que en C++ esta estrategia puede ser reemplazada por puro polimorfismo.

Cree la interfaz "ISpawnable" para discriminar los actores que pueden ser generador por el Spawner de los que no.

Luego de crear la clase base para el Spawner, me decidí a separar la implementación de "Spawn" en un componente llamado "USpawnerComponent".
Además, el SpawnerActor posee la interfaz "IInteractable", que será utilizada por el jugador para, justamente, interactuar con el Spawner, nuevamente usando una interfaz como intermediario.

Dado que el SpawnerActor necesita aplicar un widget al player cuando este interactúa con él, cree la interfaz llamada "IWidgetRequester", esta interfaz la implementa el PlayerController y le permite al Spawner solicitarle al jugador la aparición del widget que el mismo necesita.

También, tome la decision de crear una clase base customizable para el UserWidget en C++.

Cree el UserWidget llamado "WBP_Spawner", el cual sería el encargado de interactuar con el Spawner para solicitarle el Spawn de actores. En este caso simplemente contiene un puntero a su Actor fuente y ejecuta su método para justamente hacer que el Spawner efectivamente genere los actores solicitados. Una opción válida y recomendada es usar Delegates para la comunicación entre los sistemas del juego y la UI, pero en este caso no lo vi necesario.

En este punto realize la migración de los assets de tercera persona del Third Person Template de Unreal para usarlos en el jugador y, además, implementé la acción Run del jugador.

Agregue un BoxCollision en NoCollision para usarlo como referencia para el área de generación de actores del Spawner, util como debug visual en editor.

Moví la implementación del Widget Blueprint a una clase específica en C++.

Termine de ajustar los "SpawnParameters" al generar los actores por parte del Spawner para que intente ajustar la posición en caso de que pueda y permitir una opción que permita la generación incluso baja una colisión o que, en cambio, no genere ese actor si su punto de spawn se encuentra bajo una colisión.

- Escribí la documentación de los .h en Inglés y los comentarios de los .cpp en Español, por costumbre y comodidad.
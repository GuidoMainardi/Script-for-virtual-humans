# Script-for-virtual-humans

## Dependências
  - [x] Unreal 4.26
  - [x] Visual Studio (com suporte para unreal)


## Novo Projeto

Antes de começar a usar os scripts é necessário criar e mapear o ambiente que será usado no projeto, para este tutorial foi escolhida uma casa simples que vai ser modelada e usada para demonstrar os comandos existentes.

(foto da casa)

### Cenário inicial

O primeiro passo é criar o cenário e adicionar uma navmesh nele, para que ela nos ajude a encontrar os caminhos de um ponto ao outro.

(foto do cenário modelado com a navmesh)

Depois de ter o cenário inicial, é preciso fazer um mapeamento dele usando as RegionBox. Cada RegionBox vai preencher um lugar no cenário e vai representar a área deste lugar. No caso da casa, temos a cozinha, a sala, o quarto e o banheiro, para cada um desses cômodos nós vamos criar uma RegionBox com o nome deste cômodo.

(foto do cenário mapeado com as regionBoxes)

Com o lugar criado e mapeado existe uma última configuração que pode ou nao ser feita, em cada RegionBox existe um atributo chamado "flags", que pode ser adicionado novos valores nele, por padrão todas RegionBox são inicializadas como "Place", porém pode-se adicionar novas marcações, para que seja possível limitar os comandos referentes a lugares aleatórios (caso desejado).

(mostrar foto das "flags”)

### Modelos

Para que seja possível utilizar novos modelos é preciso inserir eles no projeto primeiro e fazer uma pequena máquina de estados para definir as animações de parado, andando e correndo. Além disso, também é necessário criar as regiões de colisão deste modelo que vai ser utilizado.

(mostrar foto do modelo, da máquina de estados e da colisão)

Por último, precisa ser adicionado no código "Agent.cpp" o caminho de cada coisa criada pelo novo modelo e adicionar no map com o nome que você deseja utilizar quando for se referir a eles nos scripts. 

(mostrar foto pegando o caminho e adicionando os valores no Agent.cpp e no map)

### Animações

Para adicionar animações o processo é parecido com os modelos da seção acima, precisa adicionar a animação no projeto e depois colocar o caminho dela no "Agent.cpp" salvando ele no map com o nome que vai ser usado no script. Uma coisa para se cuidar é que as animações são ligadas ao modelo, então cada modelo deve ter a sua animação e ter um nome diferente no map, como por exemplo as animações de "dance" e "macarenaDance", que são iguais, porem para modelos diferentes.

(mostrar foto adicionando as animações no Agent.cpp)

## Perfil

Perfil é a principal forma de distinguir os agentes, quando eles são criados eles recebem um perfil e são chamados por ele. Por exemplo, quando eu crio um agente com o perfil "walker" ele vai responder a comandos que mandem todos os walkers seguir algum comportamento e vai acionar eventos previstos quando um walker se direcionar para alguma RegionBox. Agentes do mesmo perfil podem ter modelos diferentes e seguem as mesmas instruções quando elas são ordenadas ao grupo(perfil) por exemplo "All Walker...". O nome de cada perfil é decidido por quem estiver escrevendo os scripts e não pode utilizar as palavras reservadas da linguagem como nomes de perfis, por exemplo (All, go, create, default...)

## Comandos

Com todo o cenário configurado, pode-se começar a escrever os scripts para comandar os agentes. Existem dois tipos de Scripts, o principal, que tem os comandos de inicialização e de eventos, e os de comportamento, que descrevem sequências de ações que serão executadas uma logo ao término da outra. O script principal deve ser chamado de "Script.txt" (mudar este nome), já os scripts de comportamento podem ter nomes arbitrários. Os nomes dos scripts de comportamento vão ser utilizados para referenciar eles no script principal. 

(mostrar foto dos scripts)

### Random

O random nao eh um comando, mas sim um jeito de se referir às regionBox, quando utilizado a palavra Random invés do nome da region box, o local alvo vai ser alguma regionBox aleatória qualquer, caso não seja desejado que todas regionBox sejam alvo deste comando, pode-se usar o Random junto com uma flag, por exemplo "Random South", assim ele vai utilizar alguma regionBox aleatórios, que tenha "South" como elemento no atributo "flags".

### Script principal

no script principal existem dois tipos de comandos, os atemporais (que devem ir no começo do script) e os temporais (que devem vir após os atemporais e seguirem uma ordem cronológica, ou seja o comando de tempo 2, não pode vir antes de um comando de tempo 1). 

#### Create

O Create eh um comando atemporal e ele serve para inicializar os agentes, informando quantos, qual perfil, qual modelo e onde. o comando mais básico eh "Create *Number* *Profile* in *Place*", assim ele vai criar *Number* agentes do perfil *Profile*, na regionBox chamada *Place*. neste comando o modelo fica implícito, mas ele pode ser definido também, usando "as" depois de informar o perfil, como por exemplo em "Create 2 Walker as Macarena in Random", assim serão criados dois agentes do perfil "Walker" com o modelo definido como "Macarena" em alguma regionBox qualquer. Quando os agentes são criados, eles recebem um "id" que vai ser utilizado para dar comandos para agentes isolados, então se tivermos, dois comandos "Create" como no exemplo abaixo.

(mostrar foto Create 2 walker as macarena in Random Create 1 Agent in Random)

Os dois agentes do perfil "Walker" terão os id’s 1 e 2 e agente de perfil "Agent" vai ter  id 3, o id é definido por ordem de criação, assim ele vai incrementando conforme os agentes vão sendo criados, se eu tiver 8 agentes os id's vão ser de 1 a 8 conforme eles foram criados no código.


#### When

O When eh o outro comando atemporal, ele vai definir eventos atemporais, quando um agente de um perfil específico, for pra um lugar específico ele vai acionar um comando, a estrutura dele fica "When *Profile* in *Place* *Command*", assim sempre que algum agente do perfil *Profile* começar a ir para o local *Place* o comando *Command* vai ser executado. O comando *Command* eh um comando do tipo temporal, que vai ser explicado abaixo, porém diferente dos comandos temporais utilizados no resto do script, este nao vai ter o "time *t*", pois vai ser acionado sempre que um agente de um determinado perfil for pra algum lugar e não quando um tempo de simulação for atingido.

#### *Profile* *ID*

Este comando é um comando do tipo temporal e define um agente único para executar um determinado comportamento. Este comando tem a estrutura "*Profile* *ID* time *t* run *Behaviour*", assim no tempo *t* o agente de id *ID* vai executar o comportamento *Behaviour*. o comportamento vai ser descrito num script de comportamento que será explicado nas seções abaixo. este comando tem algumas variações, como por exemplo "All *Profile* time *t* run *Behaviour*", assim todos agentes que forem do perfil *Profile* vão executar o script *Behaviour*. Outra variação possível é o uso de loop no lugar de run, onde invés de rodar uma única vez o comportamento, eles ficam repetindo as ações infinitamente. Estes comandos se sobrepõem às ações que estavam sendo executadas anteriormente, ou seja, se um agente estava executando um comportamento e chega um comando para ele executar um outro comportamento, ele para a execução antiga e começa a executar a nova.

### Behaviour Commands
Os comandos de comportamento são os mais simples e tem instruções diretas, são chamados dentro de um Script de comportamento, eles são executados um logo apos a finalização do outro, quando estão dentro do mesmo script e podem ser interrompidos por novos comandos dados através do script principal.

#### Go to
O comando go to ordena que o agente vá para algum lugar, e eh utilizado junto com as RegionBoxes a estrutura dele eh bem simples: "go to *Place*", assim o agente que estiver rodando este comando vai começar a ir para um ponto aleatório dentro da regionbox *Place*. A regionBox deste comando também pode ser descrita como "Random" junto com as flags definidas pelo programador, por exemplo "Random South".

#### play
O comando play serve para iniciar um animação, durante o tempo da animação o agente fica parado executando ela. o comando tem a estrutura "play *anim*" onde *anim* eh a chave adicionada no map em "Agent.cpp", vale ressaltar que as animações são ligadas ao modelo, então caso seja ordenado que um modelo rode uma animação que nao eh dele, ele vai ficar parado em posição neutra pelo tempo da animação, antes de seguir executando os próximos comandos.

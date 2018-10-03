#ifndef IP_PROTOCOLO_TESTE_H_INCLUDED
#define IP_PROTOCOLO_TESTE_H_INCLUDED

#include "IP_PROJETO_TESTE1.h"

#define PROTO_ENTRADA
PROTO_ENTRADA *pro_ent;

#define PROTO_TAMANHO
PROTO_TAMANHO *pro_tam;

#define PROTO_RETORNO
PROTO_RETORNO *pro_ret;

#if TCP == 1
    #define PROTO_TCP_ENTRADA
    PROTO_TCP_ENTRADA = pro_ent;
#endif

#if UDP == 1
    #define PROTO_UDP_ENTRDA
    PROTO_UDP_ENTRDA = pro_ent;
#endif

#if FTP == 1
    #define PROTO_FTP_ENTRADA
    PROTO_FTP_ENTRADA = pro_ent;
#endif


#endif // IP_PROTOCOLO_TESTE_H_INCLUDED
/**
TTL=0   REFERENCIA DE ENTRADA DE BITS OU DADOS QUE RETORNAO UMA INFORMAÇÃO
ICMP=10 REFERENCIA DE TIME OU TEMPO DE RESPOSTA CASA ALGO NO PROTOCOLO NÃO OCORRA BEM

*/

/**
1  Introdução

    Este documento especifica um método pelo qual um datagrama IP pode ser
    encapsulado (transportado como payload) dentro de um datagrama IP.
    O encapsulamento é sugerido como um meio de alterar o roteamento IP normal
    para datagramas, entregando-os a um destino intermediário que
    caso contrário, não seria selecionado com base na (parte da rede do) IP
    Campo Endereço de Destino no cabeçalho IP original.  Uma vez o
    datagrama encapsulado chega a esse nó de destino intermediário,
    é decapsulado, produzindo o datagrama IP original, que é então
    entregue no destino indicado pelo Destino original
    Campo Endereço.  Este uso de encapsulamento e decapsulation de um
    datagrama é freqüentemente chamado de "tunelamento" do datagrama, e
    o encapsulador e o decapsulador são então considerados os
    "pontos finais" do túnel.

    No caso de encapsulamento mais geral, temos

       fonte ---> encapsulador --------> decapsulador ---> destino
*/

/**
 3  IP no encapsulamento IP

    Para encapsular um datagrama IP usando IP no encapsulamento IP, um
    O cabeçalho IP [ 10 ] é inserido antes do cabeçalho IP existente do datagrama,
    do seguinte modo:

                                          + --------------------------- +
                                          |  |
                                          |  Cabeçalho IP Externo |
                                          |  |
      + --------------------------- + + -------------------- ------- +
      |  |  |  |
      |  Cabeçalho IP |  |  Cabeçalho IP |
      |  |  |  |
      + --------------------------- + ====> + --------------- ------------ +
      |  |  |  |
      |  |  |  |
      |  Carga IP |  |  Carga IP |
      |  |  |  |
      |  |  |  |
      + --------------------------- + + -------------------- ------- +

    O endereço de origem do cabeçalho IP externo e o endereço de destino identificam
    os "endpoints" do túnel.  O endereço IP da fonte do cabeçalho interno
    e Destination Addresses identificam o remetente e o destinatário originais
    do datagrama, respectivamente.  O cabeçalho IP interno não é alterado por
    encapsulador, exceto para diminuir o TTL como indicado abaixo, e
    permanece inalterada durante a sua entrega ao ponto de saída do túnel.  Não
    mudança para opções de IP no cabeçalho interno ocorre durante a entrega de
    o datagrama encapsulado através do túnel.  Se necessário, outro
    cabeçalhos de protocolo, como o cabeçalho IP Authentication [ 1 ], podem ser
    inserido entre o cabeçalho IP externo e o cabeçalho IP interno.  Nota
    que as opções de segurança do cabeçalho IP interno PODEM afetar
    escolha de opções de segurança para o encapsulamento (externo) do cabeçalho IP.
*/

/**
    3.1 - SE O DATAGRAMA FOR ENVIADO INTERNAMENTE
     - Se o endereço de origem IP do datagrama corresponder ao próprio do roteador
        Endereço IP em qualquer uma das suas interfaces de rede, o roteador NÃO
        tunelize o datagrama;  em vez disso, o datagrama deve ser descartado.

     - Se o endereço IP de origem do datagrama corresponder ao endereço IP
        do destino do túnel (o ponto de saída do túnel é tipicamente
        escolhido pelo roteador com base no endereço de destino no
        cabeçalho IP do datagrama), o roteador não deve encapsular o datagrama;
        em vez disso, o datagrama deve ser descartado.


*/

/**
4  Mensagens ICMP de dentro do túnel

    Após um datagrama encapsulado ter sido enviado, o encapsulador pode
    receber uma mensagem ICMP [ 9 ] de qualquer roteador intermediário
    túnel diferente do ponto de saída do túnel.  A ação tomada pelo
    O encapsulador depende do tipo de mensagem ICMP recebida.  Quando o
    mensagem recebida contém informações suficientes, o encapsulador
    use a mensagem recebida para criar uma mensagem ICMP similar, a ser enviada
    para o originador do datagrama IP não encapsulado original (o
    remetente original).  Este processo será referido como "retransmitir"
    Mensagem ICMP do túnel.

    Mensagens ICMP indicando um erro no processamento de um datagrama incluem
    cópia de (uma parte do) datagrama que causa o erro.  Retransmitindo um
    A mensagem ICMP requer que o encapsulador remova o IP externo
    cabeçalho desta cópia retornada do datagrama original.  Para casos
    em que a mensagem ICMP recebida não contém dados suficientes para
    retransmitir a mensagem, consulte a Seção 5 .

    Rede Inacessível (Código 0)
          Uma mensagem de destino inacessível do ICMP DEVE ser retornada

       Anfitrião inacessível (código 1)
          O encapsulador DEVE transmitir as mensagens do Host Unreachable para o

       Protocolo Inacessível (Código 2)
          Quando o encapsulador recebe um protocolo ICMP inacessível

       Porto Inacessível (Código 3)
          Este Código nunca deve ser recebido pelo encapsulador, uma vez que

       Datagrama muito grande (código 4)
          O encapsulador deve retransmitir as mensagens ICMP Datagram Too Big para

       Falha na rota de origem (código 5)
          Este código deve ser tratado pelo próprio encapsulador.

*/

/**
5  Gerenciamento de Túnel

    Infelizmente, o ICMP requer apenas que os roteadores IP retornem 8 octetos (64
    bits) do datagrama além do cabeçalho IP.  Isso não é suficiente para
    incluir uma cópia do encapsulado (interno) IP cabeçalho, por isso não é
    sempre possível para o encapsulamento retransmitir a mensagem ICMP de
    o interior de um túnel de volta ao remetente original.  No entanto, por
    cuidadosamente mantendo o "estado suave" dos túneis nos quais ele envia,
    o encapsulador pode retornar mensagens ICMP precisas ao original
    remetente na maioria dos casos.  O encapsulador DEVE manter pelo menos o
    seguinte informação de estado suave sobre cada túnel:

     - MTU do túnel ( secção 5.1 )
     - TTL (comprimento do caminho) do túnel
     - Acessibilidade do fim do túnel

    O encapsulador usa as mensagens ICMP que recebe do interior
    de um túnel para atualizar as informações de estado suaves para esse túnel.
    Erros ICMP que poderiam ser recebidos de um dos roteadores ao longo do
    interior do túnel incluem:

     - datagrama muito grande
     - Tempo excedido
     - Destino inalcançável
     - Source Quench
*/

/**

*/

/**

 PROTOCOLO DE CONTROLE DE TRANSMISSÃO

                          PROGRAMA DARPA INTERNET

                          ESPECIFICAÇÃO DO PROTOCOLO


                              Setembro de 1981



                               preparado para

                Agência de Projetos de Pesquisa Avançada de Defesa
                 Escritório de Técnicas de Processamento de Informação
                          1400 Wilson Boulevard
                        Arlington, Virgínia 22209


                                    de

                      Instituto de Ciências da Informação
                    Universidade do Sul da California
                            4676 Admiralty Way
                    Marina del Rey, Califórnia 90291


 Setembro de 1981
                                            protocolo de Controle de Transmissão

                            ÍNDICE
     PREFÁCIO ................................................. ....... iii

 1  INTRODUÇÃO ................................................. .... 1

   1.1 Motivação ................................................ .... 1
   1.2 Escopo ................................................ ......... 2
   1.3 Sobre este documento ........................................... 2
   1.4 Interfaces ................................................ .... 3
   1.5 Operação ................................................ ..... 3

 2  FILOSOFIA ................................................. ...... 7

   2.1 Elementos do Sistema Internetwork ........................... 7
   2.2 Modelo de Operação ............................................ 7
   2.3 O Ambiente Host .......................................... 8
   2.4 Interfaces ................................................ .... 9
   2.5 Relação com outros protocolos ................................... 9
   2.6 Comunicação Confiável ........................................ 9
   2.7 Estabelecimento de Conexão e Compensação ........................ 10
   2.8 Comunicação de Dados ........................................... 12
   2.9 Precedência e Segurança ........................................ 13
   2.10 Princípio da Robustez ......................................... 13

 3  ESPECIFICAÇÃO FUNCIONAL ........................................ 15

   3.1 Formato do cabeçalho ............................................... 15
   3.2 Terminologia ................................................ .. 19
   3.3 Números de Sequência ............................................. 24
   3.4 Estabelecendo uma conexão .................................... 30
   3.5 Fechando uma conexão ......................................... 37
   3.6 Precedência e Segurança ...................................... 40
   3.7 Comunicação de Dados ........................................... 40
   3.8 Interfaces ................................................ ... 44
   3.9 Processamento de Eventos ............................................. 52

 GLOSSÁRIO ................................................. ........... 79

 REFERÊNCIAS ................................................. ......... 85

 [Página i]
 Setembro de 1981
 protocolo de Controle de Transmissão

 [Página ii]
 Setembro de 1981
                    protocolo de Controle de Transmissão
                                 PREFÁCIO

 Este documento descreve o Protocolo de Controle de Transmissão Padrão do DoD
 (TCP).  Houve nove edições anteriores do ARPA TCP
 especificação na qual esta norma é baseada, e o texto atual
 atrai fortemente deles.  Houve muitos contribuintes para este trabalho
 tanto em termos de conceitos quanto em termos de texto.  Esta edição esclarece
 vários detalhes e remove os ajustes de tamanho de buffer de final de letra,
 e redescreve o mecanismo de letras como uma função push.

                                                            Jon Postel

                                                            editor
 [Página iii]
 RFC: 793
 Substitui: RFC 761
 IENs: 129, 124, 112, 81,
 55, 44, 40, 27, 21, 5

                      PROTOCOLO DE CONTROLE DE TRANSMISSÃO

                          PROGRAMA DARPA INTERNET
                          ESPECIFICAÇÃO DO PROTOCOLO

                             1. INTRODUÇÃO

 O Protocolo de Controle de Transmissão (TCP) destina-se a ser usado
 protocolo host-to-host confiável entre hosts no computador comutado por pacote
 redes de comunicação e nos sistemas interligados dessas redes.

 Este documento descreve as funções a serem executadas pelo
 Transmission Control Protocol, o programa que o implementa e seus
 interface para programas ou usuários que requerem seus serviços.

 1.1 .  Motivação

   Sistemas de comunicação por computador estão desempenhando um papel cada vez mais importante
   papel em ambientes militares, governamentais e civis.  este
   documento concentra sua atenção principalmente no computador militar
   requisitos de comunicação, especialmente robustez na presença de
   falta de confiabilidade e disponibilidade de comunicação na presença de
   congestionamento, mas muitos desses problemas são encontrados em civis e
   setor governamental também.

   Como redes estratégicas e táticas de comunicação por computador
   desenvolvidos e implantados, é essencial fornecer meios de
   interconectando-os e fornecendo um interprocesso padrão
   protocolos de comunicação que podem suportar uma ampla gama de
   aplicações.  Antecipando a necessidade de tais padrões, o
   Vice-Subsecretário de Defesa para Pesquisa e Engenharia
   declarou o Protocolo de Controle de Transmissão (TCP) descrito aqui
   ser uma base para o protocolo de comunicação entre processos do DoD
   estandardização.

   O TCP é um protocolo confiável de ponta a ponta orientado a conexão, projetado para
   caber em uma hierarquia em camadas de protocolos que suportam multi-rede
   aplicações.  O TCP fornece confiabilidade entre processos
   comunicação entre pares de processos em computadores host conectados a
   redes de comunicação de computador distintas, mas interconectadas.  Muito pouco
   suposições são feitas quanto à confiabilidade da comunicação
   protocolos abaixo da camada TCP.  O TCP assume que pode obter um
   serviço de datagrama potencialmente não confiável do nível inferior
   protocolos.  Em princípio, o TCP deve ser capaz de operar acima de
   amplo espectro de sistemas de comunicação que variam de hard-wired
   ligações a redes comutadas por pacotes ou por comutação de circuitos.

 [Página 1]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Introdução

   O TCP é baseado em conceitos descritos pela primeira vez por Cerf e Kahn em [ 1 ].  o
   TCP se encaixa em uma arquitetura de protocolo em camadas logo acima de uma base
   Internet Protocol [ 2 ], que fornece uma maneira para o TCP enviar e
   receber segmentos de informação de tamanho variável dentro da internet
   datagrama "envelopes".  O datagrama da Internet fornece um meio para
   endereçamento TCPs de origem e destino em diferentes redes.  o
   protocolo de internet também lida com qualquer fragmentação ou remontagem de
   os segmentos TCP necessários para obter transporte e entrega por meio
   várias redes e gateways de interconexão.  O protocolo da internet
   também traz informações sobre a precedência, classificação de segurança
   compartimentação dos segmentos TCP, portanto, esta informação pode ser
   comunicados de ponta a ponta em várias redes.

                            Camadas de protocolo

                         + --------------------- +
                         |  nível superior |
                         + --------------------- +
                         |  TCP |
                         + --------------------- +
                         |  protocolo de internet |
                         + --------------------- +
                         rede de comunicação |
                         + --------------------- +

                                 figura 1

   Grande parte deste documento é escrito no contexto de implementações do TCP
   que são co-residentes com protocolos de alto nível no hospedeiro
   computador.  Alguns sistemas de computadores serão conectados a redes via
   computadores front-end que abrigam as camadas de protocolos TCP e Internet,
   bem como software específico da rede.  A especificação TCP descreve
   uma interface para os protocolos de nível superior que parece ser
   implementável mesmo para o caso front-end, desde que um adequado
   O protocolo final do host para o front é implementado.

 1.2 .  Escopo

   O TCP destina-se a fornecer um processo confiável para processar
   serviço de comunicação em um ambiente de multinetwork.  O TCP é
   destina-se a ser um protocolo host-to-host de uso comum em múltiplos
   redes.

 1.3 .  Sobre este documento

   Este documento representa uma especificação do comportamento exigido de
   qualquer implementação TCP, tanto em suas interações com nível superior
   protocolos e em suas interações com outros TCPs.  O resto disto

 [Página 2]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                             Introdução

   seção oferece uma breve visão das interfaces de protocolo e
   Operação.  A seção 2 resume a base filosófica para o TCP
   desenhar.  A seção 3 oferece uma descrição detalhada das ações
   exigido do TCP quando ocorrem vários eventos (chegada de novos segmentos,
   chamadas de usuário, erros, etc.) e os detalhes dos formatos de TCP
   segmentos.

 1.4 .  Interfaces

   As interfaces TCP de um lado para os processos de usuário ou aplicativo e
   o outro lado para um protocolo de nível inferior, como o Internet Protocol.

   A interface entre um processo de aplicação e o TCP é
   ilustrado com detalhes razoáveis.  Essa interface consiste em um conjunto de
   chama muito parecido com as chamadas de um sistema operacional fornece a um
   processo de aplicação para manipular arquivos.  Por exemplo, existem
   chamadas para abrir e fechar conexões e para enviar e receber dados sobre
   conexões estabelecidas.  Espera-se também que o TCP possa
   comunicar de forma assíncrona com programas aplicativos.  Apesar
   É permitida uma liberdade considerável aos implementadores do TCP para projetar
   interfaces que são apropriadas para um sistema operacional específico
   ambiente, uma funcionalidade mínima é necessária no TCP / usuário
   interface para qualquer implementação válida.

   A interface entre TCP e protocolo de nível inferior é essencialmente
   não especificado, exceto que é assumido que existe um mecanismo pelo qual o
   dois níveis podem passar informações de maneira assíncrona entre si.
   Normalmente, espera-se que o protocolo de nível inferior especifique
   interface.  O TCP foi projetado para funcionar em um ambiente muito geral de
   redes interconectadas.  O protocolo de nível inferior que é assumido
   ao longo deste documento é o Internet Protocol [ 2 ].

 1.5 .  Operação

   Como observado acima, o objetivo principal do TCP é fornecer informações confiáveis ​​e
   circuito lógico protegível ou serviço de conexão entre pares de
   processos.  Para fornecer este serviço em cima de uma internet menos confiável
   sistema de comunicação requer instalações nas seguintes áreas:

     Transferência Básica de Dados
     Confiabilidade
     Controle de fluxo
     Multiplexação
     Conexões
     Precedência e Segurança

   A operação básica do TCP em cada uma dessas áreas é descrita em
   os parágrafos seguintes.

 [Página 3]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Introdução
   Transferência de dados básica:

     O TCP é capaz de transferir um fluxo contínuo de octetos em cada
     direção entre seus usuários, empacotando um certo número de octetos
     segmentos de transmissão através do sistema de internet.  Em geral,
     os TCPs decidem quando bloquear e encaminhar dados por conta própria
     conveniência.

     Às vezes, os usuários precisam ter certeza de que todos os dados que possuem
     enviado para o TCP foi transmitido.  Para este propósito, um empurrão
     função é definida.  Para garantir que os dados submetidos a um TCP sejam
     na verdade, transmitiu o usuário de envio indica que deve ser
     empurrado através do usuário receptor.  Um push faz com que os TCPs
     prontamente encaminhar e entregar dados até aquele ponto ao receptor.
     O ponto de envio exato pode não estar visível para o usuário receptor e
     a função push não fornece um marcador de limite de registro.

   Confiabilidade:

     O TCP deve recuperar dados danificados, perdidos, duplicados ou
     entregue fora de ordem pelo sistema de comunicação da Internet.  este
     é conseguido atribuindo um número de sequência a cada octeto
     transmitido e exigindo uma confirmação positiva (ACK) do
     recebendo TCP.  Se o ACK não for recebido dentro de um tempo limite
     intervalo, os dados são retransmitidos.  No receptor, a sequência
     números são usados ​​para ordenar corretamente segmentos que podem ser recebidos
     fora de ordem e para eliminar duplicatas.  O dano é tratado por
     adicionando uma soma de verificação a cada segmento transmitido, verificando
     receptor e descartar segmentos danificados.

     Enquanto os TCPs continuarem funcionando corretamente e a internet
     sistema não se torna completamente particionado, nenhuma transmissão
     os erros afetarão a entrega correta dos dados.  TCP recupera de
     erros do sistema de comunicação na internet.

   Controle de fluxo:

     O TCP fornece um meio para o receptor governar a quantidade de dados
     enviado pelo remetente.  Isto é conseguido retornando uma "janela" com
     cada ACK indicando um intervalo de números de sequência aceitáveis ​​além
     o último segmento recebido com sucesso.  A janela indica um
     número permitido de octetos que o remetente pode transmitir antes
     recebendo mais permissão.

 [Página 4]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                             Introdução
   Multiplexação:

     Para permitir que muitos processos em um único host usem o TCP
     facilidades de comunicação simultaneamente, o TCP fornece um conjunto de
     endereços ou portas dentro de cada host.  Concatenado com a rede
     endereços de host da camada de comunicação da Internet,
     uma tomada.  Um par de soquetes identifica exclusivamente cada conexão.
     Isto é, um soquete pode ser usado simultaneamente em
     conexões.

     A ligação de portas a processos é tratada independentemente por cada
     Hospedeiro.  No entanto, é útil anexar processos usados ​​com freqüência
     (por exemplo, um "logger" ou serviço de compartilhamento de tempo) para soquetes fixos que são
     divulgado ao público.  Esses serviços podem ser acessados
     através dos endereços conhecidos.  Estabelecendo e aprendendo o porto
     endereços de outros processos podem envolver mecanismos mais dinâmicos.

   Conexões:

     Os mecanismos de confiabilidade e controle de fluxo descritos acima
     TCPs inicializam e mantêm certas informações de status para
     cada fluxo de dados.  A combinação dessas informações, incluindo
     soquetes, números de seqüência e tamanhos de janela, é chamado de conexão.
     Cada conexão é especificada exclusivamente por um par de soquetes
     identificando seus dois lados.

     Quando dois processos desejam se comunicar, seus TCPs devem primeiro
     estabelecer uma conexão (inicializar as informações de status em cada
     lado).  Quando a comunicação é concluída, a conexão é
     terminado ou fechado para liberar os recursos para outros usos.

     Como as conexões devem ser estabelecidas entre hosts não confiáveis ​​e
     sobre o sistema de comunicação de internet não confiável, um aperto de mão
     mecanismo com números de sequência baseados no relógio é usado para evitar
     inicialização errônea de conexões.

   Precedência e Segurança:

     Os usuários do TCP podem indicar a segurança e a precedência de seus
     comunicação.  Provisão é feita para valores padrão a serem usados ​​quando
     esses recursos não são necessários.

 [Página 5]
 Setembro de 1981
 protocolo de Controle de Transmissão

 [Página 6]
 Setembro de 1981
                                            protocolo de Controle de Transmissão

                              2. FILOSOFIA

 2.1 .  Elementos do sistema de inter-redes

   O ambiente de internetwork consiste em hosts conectados a redes
   que por sua vez são interligados através de gateways.  Assume-se aqui
   que as redes podem ser redes locais (por exemplo, o ETHERNET) ou
   grandes redes (por exemplo, a ARPANET), mas em qualquer caso são baseadas em
   tecnologia de comutação de pacotes.  Os agentes ativos que produzem e
   consumir mensagens são processos.  Vários níveis de protocolos no
   redes, os gateways e os hosts suportam um interprocesso
   sistema de comunicação que fornece fluxo de dados bidirecional em
   conexões entre portas de processo.

   O termo pacote é usado genericamente aqui para significar os dados de um
   transação entre um host e sua rede.  O formato dos blocos de dados
   trocado dentro de uma rede geralmente não será motivo de preocupação para nós.

   Hosts são computadores conectados a uma rede e, a partir da comunicação
   ponto de vista da rede, são as fontes e os destinos dos pacotes.
   Os processos são vistos como os elementos ativos nos computadores host (em
   de acordo com a definição bastante comum de um processo como um programa
   em execução).  Até terminais e arquivos ou outros dispositivos de E / S são
   vistos como comunicação entre si através do uso de processos.
   Assim, toda comunicação é vista como comunicação entre processos.

   Como um processo pode precisar distinguir entre várias comunicações
   fluxos entre si e outro processo (ou processos), imaginamos
   que cada processo pode ter um número de portas através do qual
   comunica-se com as portas de outros processos.

 2.2 .  Modelo de Operação

   Processos transmitem dados chamando o TCP e passando buffers de
   dados como argumentos.  O TCP empacota os dados desses buffers em
   segmentos e chamadas no módulo internet para transmitir cada segmento para
   o destino TCP.  O TCP receptor coloca os dados de um segmento
   no buffer do usuário receptor e notifica o usuário receptor.  o
   TCPs incluem informações de controle nos segmentos que eles usam para
   garantir a transmissão de dados ordenada confiável.

   O modelo de comunicação pela internet é que existe uma internet
   módulo de protocolo associado a cada TCP que fornece uma interface
   para a rede local.  Este módulo de internet contém os segmentos TCP
   dentro de datagramas da Internet e encaminha esses datagramas para um destino
   módulo de internet ou gateway intermediário.  Para transmitir o datagrama
   através da rede local, é incorporado em um pacote de rede local.

   Os comutadores de pacotes podem realizar outras embalagens, fragmentação ou

 [Página 7]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Filosofia

   outras operações para alcançar a entrega do pacote local ao
   módulo de internet de destino.

   Em um gateway entre redes, o datagrama da Internet é "desembrulhado"
   de seu pacote local e examinado para determinar por meio de qual rede
   o datagrama da internet deve seguir em frente.  O datagrama da internet é
   então "embrulhado" em um pacote local adequado para a próxima rede e
   encaminhado para o próximo gateway ou para o destino final.

   Um gateway é permitido para dividir um datagrama da Internet em menor
   fragmentos de datagramas da Internet, se isso for necessário para a transmissão
   através da próxima rede.  Para fazer isso, o gateway produz um conjunto de
   datagramas de internet;  cada um carregando um fragmento.  Fragmentos podem ser
   mais dividido em fragmentos menores nos portais subsequentes.  o
   O formato de fragmento de datagramas da Internet foi concebido para que o destino
   módulo de internet pode remontar fragmentos em datagramas de internet.

   Um módulo de internet de destino desembrulha o segmento do datagrama
   (depois de remontar o datagrama, se necessário) e passa-o para o
   TCP de destino.

   Este modelo simples da operação encobre muitos detalhes.  1
   característica importante é o tipo de serviço.  Isso fornece informações
   para o gateway (ou módulo de internet) para guiá-lo na seleção do
   Parâmetros de serviço a serem usados ​​na travessia da próxima rede.
   Incluído no tipo de informação de serviço está a precedência do
   datagrama.  Os datagramas também podem conter informações de segurança para permitir
   host e gateways que operam em ambientes seguros de vários níveis para
   Separe adequadamente os datagramas para considerações de segurança.

 2.3 .  O ambiente host

   O TCP é considerado um módulo em um sistema operacional.  Os usuários
   acesse o TCP da mesma forma que eles acessariam o sistema de arquivos.  O TCP
   pode chamar outras funções do sistema operacional, por exemplo, para gerenciar
   estruturas de dados.  A interface real da rede é considerada como sendo
   controlado por um módulo de driver de dispositivo.  O TCP não invoca o
   driver de dispositivo de rede diretamente, mas sim chama na internet
   módulo de protocolo de datagramas que, por sua vez, pode chamar o driver do dispositivo.

   Os mecanismos do TCP não impedem a implementação do TCP em um
   processador front-end.  No entanto, em tal implementação, um
   protocolo host-to-front-end deve fornecer a funcionalidade para suportar
   o tipo de interface do usuário TCP descrito neste documento.

 [Página 8]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                               Filosofia
 2.4 .  Interfaces

   A interface TCP / usuário fornece as chamadas feitas pelo usuário no TCP
   para ABRIR ou FECHAR uma conexão, para ENVIAR ou RECEBER dados, ou para obter
   STATUS sobre uma conexão.  Essas chamadas são como outras chamadas do usuário
   programas no sistema operacional, por exemplo, as chamadas para abrir, ler
   de e feche um arquivo.

   A interface TCP / internet fornece chamadas para enviar e receber
   datagramas endereçados a módulos TCP em hosts em qualquer lugar da internet
   sistema.  Essas chamadas têm parâmetros para passar o endereço, tipo de
   serviço, precedência, segurança e outras informações de controle.

 2.5 .  Relação com outros protocolos

   O diagrama a seguir ilustra o local do TCP no protocolo
   hierarquia:


        + ------ + + ----- + + ----- + + ----- +
        Telnet |  |  FTP |  | Voz |  ... |  |  Nível de aplicação
        + ------ + + ----- + + ----- + + ----- +
              |  |  |  |
             + ----- + + ----- + + ----- +
             |  TCP |  |  RTP |  ... |  |  Nível de host
             + ----- + + ----- + + ----- +
                |  |  |
             + ------------------------------- +
             |  Protocolo de Internet e ICMP |  Nível do gateway
             + ------------------------------- +
                            |
               + --------------------------- +
               |  Protocolo de Rede Local |  Nível de rede
               + --------------------------- +

                          Relacionamentos de protocolo

                                Figura 2.

   Espera-se que o TCP seja capaz de suportar um nível mais alto
   protocolos de forma eficiente.  Deve ser fácil de interface de nível superior
   protocolos como o ARPANET Telnet ou o AUTODIN II THP para o TCP.

 2.6 .  Comunicação Confiável

   Um fluxo de dados enviados em uma conexão TCP é entregue de forma confiável e
   ordem no destino.

 [Página 9]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Filosofia

   A transmissão é confiável através do uso de números de seqüência e
   reconhecimentos.  Conceitualmente, cada octeto de dados recebe um
   número sequencial.  O número de seqüência do primeiro octeto de dados em um
   segmento é transmitido com esse segmento e é chamado de segmento
   número sequencial.  Os segmentos também carregam um número de confirmação que
   é o número de sequência do próximo octeto de dados esperado de
   transmissões no sentido inverso.  Quando o TCP transmite um
   segmento contendo dados, ele coloca uma cópia em uma fila de retransmissão e
   inicia um temporizador;  quando o reconhecimento desses dados for recebido, o
   segmento é excluído da fila.  Se a confirmação não for
   recebido antes que o tempo se esgote, o segmento é retransmitido.

   Um reconhecimento pelo TCP não garante que os dados tenham sido
   entregue ao usuário final, mas apenas que o TCP receptor recebeu
   a responsabilidade de fazê-lo.

   Para governar o fluxo de dados entre os TCPs, um mecanismo de controle de fluxo é
   empregado.  O TCP receptor reporta uma "janela" para o TCP de envio.
   Esta janela especifica o número de octetos, começando com o
   número de confirmação, que o TCP receptor está atualmente preparado para
   receber.

 2.7 .  Estabelecimento de conexão e compensação

   Para identificar os fluxos de dados separados que um TCP pode manipular, o TCP
   fornece um identificador de porta.  Como os identificadores de porta estão selecionados
   independentemente por cada TCP eles podem não ser únicos.  Para fornecer
   endereços exclusivos dentro de cada TCP, nós concatenamos um endereço de internet
   identificando o TCP com um identificador de porta para criar um soquete que
   será único em todas as redes conectadas.

   Uma conexão é totalmente especificada pelo par de soquetes nas extremidades.  UMA
   soquete local pode participar em muitas conexões com diferentes
   tomadas.  Uma conexão pode ser usada para transportar dados em ambas as direções,
   isto é, é "full duplex".

   Os TCPs são livres para associar portas a processos da maneira que escolherem.
   No entanto, vários conceitos básicos são necessários em qualquer implementação.
   Deve haver soquetes conhecidos que o TCP associa apenas a
   os processos "apropriados" de alguma forma.  Nós imaginamos que processos
   podem "possuir" portas, e esses processos podem iniciar conexões somente
   os portos que eles possuem.  (Os meios para implementar a propriedade são um
   problema, mas imaginamos um comando de usuário Request Port, ou um método de
   alocando unicamente um grupo de portas a um dado processo, por exemplo,
   associando os bits de alta ordem de um nome de porta a um determinado processo.)

   Uma conexão é especificada na chamada OPEN pela porta local e
   argumentos soquete estrangeiros.  Em troca, o TCP fornece um local (curto)

 [Página 10]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                               Filosofia

   nome da conexão pelo qual o usuário se refere à conexão em
   chamadas subseqüentes.  Existem várias coisas que devem ser lembradas
   sobre uma conexão.  Para armazenar essas informações, imaginamos que
   é uma estrutura de dados chamada um bloco de controle de transmissão (TCB).  1
   estratégia de implementação teria o nome da conexão local ser um
   ponteiro para o TCB para esta conexão.  A chamada OPEN também especifica
   se o estabelecimento de conexão deve ser ativamente perseguido, ou
   ser esperado passivamente.

   Uma solicitação OPEN passiva significa que o processo deseja aceitar
   solicitações de conexão, em vez de tentar iniciar uma conexão.
   Muitas vezes, o processo solicitando um OPEN passivo aceitará uma conexão
   pedido de qualquer chamador.  Neste caso, uma tomada estrangeira de todos os zeros
   é usado para denotar um soquete não especificado.  Tomadas estrangeiras não especificadas
   são permitidos somente em OPENs passivos.

   Um processo de serviço que desejava fornecer serviços para outros desconhecidos
   processos iria emitir um pedido OPEN passivo com um não especificado
   tomada estrangeira.  Então, uma conexão poderia ser feita com qualquer processo que
   solicitou uma conexão a este soquete local.  Ajudaria se isso
   local socket eram conhecidos por estarem associados a este serviço.

   Soquetes bem conhecidos são um mecanismo conveniente para uma associação a priori
   um endereço de soquete com um serviço padrão.  Por exemplo, o
   O processo "Telnet-Server" é permanentemente atribuído a um determinado
   soquete e outros soquetes são reservados para transferência de arquivos, trabalho remoto
   Processos Entry, Text Generator, Echoer e Sink (os últimos três
   sendo para fins de teste).  Um endereço de soquete pode ser reservado para
   acesso a um serviço "Look-Up" que retornaria o soquete específico
   em que um serviço recém-criado seria fornecido.  O conceito de um
   soquete bem conhecido é parte da especificação TCP, mas a atribuição
   de soquetes para serviços está fora desta especificação.  (Veja [ 4 ].)

   Processos podem emitir OPENs passivos e esperar por OPENs ativos correspondentes
   de outros processos e ser informado pelo TCP quando as conexões
   foi estabelecido.  Dois processos que emitem OPENs ativos para cada
   outros ao mesmo tempo serão conectados corretamente.  Esta flexibilidade
   é fundamental para o suporte de computação distribuída em que
   os componentes atuam de forma assíncrona em relação um ao outro.

   Existem dois casos principais para combinar os soquetes no local
   OPENs passivos e OPENs ativos estrangeiros.  No primeiro caso, o
   O OPENs passivo local especificou completamente o socket estrangeiro.  Nisso
   caso, o jogo deve ser exato.  No segundo caso, o passivo local
   OPENs deixou o soquete estrangeiro não especificado.  Neste caso, qualquer
   soquete estrangeiro é aceitável desde que os soquetes locais correspondam.
   Outras possibilidades incluem correspondências parcialmente restritas.

 [Página 11]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Filosofia

   Se houver vários OPENs passivos pendentes (registrados em TCBs) com o
   mesmo soquete local, um OPEN ativo estrangeiro será correspondido a um TCB
   com o soquete estrangeiro específico no ativo estrangeiro OPEN, se tal
   O TCB existe, antes de selecionar um TCB com um soquete externo não especificado.

   Os procedimentos para estabelecer conexões utilizam a sincronização (SYN)
   bandeira de controle e envolve uma troca de três mensagens.  este
   troca foi denominado um shake de mão de três vias [ 3 ].

   Uma conexão é iniciada pelo encontro de um segmento que chega
   contendo um SYN e uma entrada TCB em espera, cada um criado por um usuário OPEN
   comando.  A correspondência de soquetes locais e externos determina quando um
   a conexão foi iniciada.  A conexão se torna "estabelecida"
   quando os números de sequência foram sincronizados em ambas as direções.

   A compensação de uma conexão também envolve a troca de segmentos,
   neste caso, carregando a bandeira de controle FIN.

 2.8 .  Comunicação de dados

   Os dados que fluem em uma conexão podem ser considerados como um fluxo de
   octetos.  O usuário remetente indica em cada chamada SEND se os dados
   nessa chamada (e quaisquer chamadas precedentes) devem ser imediatamente
   até o usuário receptor pela configuração do sinalizador PUSH.

   Um TCP remetente tem permissão para coletar dados do usuário remetente e para
   enviar esses dados em segmentos em sua própria conveniência, até o
   função é sinalizada, então deve enviar todos os dados não enviados.  Quando um
   receber TCP vê o sinalizador PUSH, ele não deve esperar por mais dados de
   o envio TCP antes de passar os dados para o processo de recebimento.

   Não há relação necessária entre as funções push e o segmento
   limites.  Os dados em qualquer segmento particular podem ser o resultado de um
   única chamada de envio, no todo ou em parte, ou de várias chamadas de envio.

   O propósito da função push e o flag PUSH é empurrar dados através
   do usuário remetente ao usuário receptor.  Não fornece um
   serviço de registro.

   Existe um acoplamento entre a função push e o uso de buffers
   de dados que atravessam a interface TCP / usuário.  Cada vez que uma bandeira PUSH é
   associados a dados colocados no buffer do usuário receptor, o
   buffer é retornado para o usuário para processamento, mesmo que o buffer seja
   não preenchido.  Se os dados chegarem, isso preencherá o buffer do usuário antes de
   PUSH é visto, os dados são passados ​​para o usuário em unidades de tamanho de buffer.

   O TCP também fornece um meio para comunicar ao receptor de dados que
   em algum momento mais adiante no fluxo de dados do que o receptor é


 [Página 12]


 Setembro de 1981
                                protocolo de Controle de Transmissão
                                            Filosofia

   atualmente lendo há dados urgentes.  TCP não tenta
   definir o que o usuário faz especificamente ao ser notificado de pendentes
   dados urgentes, mas a noção geral é que o processo de recepção
   tomar medidas para processar os dados urgentes rapidamente.

 2.9 .  Precedência e Segurança

   O TCP faz uso do campo de tipo de protocolo de acesso à Internet e
   opção de segurança para fornecer precedência e segurança em uma conexão por
   base para os usuários do TCP.  Nem todos os módulos TCP funcionarão necessariamente
   um ambiente seguro de vários níveis;  alguns podem estar limitados a não classificados
   somente uso, e outros podem operar em apenas um nível de segurança e
   compartimento.  Consequentemente, algumas implementações e serviços TCP para
   os usuários podem estar limitados a um subconjunto do caso seguro de vários níveis.

   Os módulos TCP que operam em um ambiente seguro de vários níveis
   marcar adequadamente os segmentos de saída com a segurança, compartimento e
   precedência.  Esses módulos TCP também devem fornecer aos seus usuários ou
   protocolos de nível superior, como Telnet ou THP uma interface para permitir
   para especificar o nível de segurança desejado, compartimento e
   precedência de conexões.

 2,10 .  Princípio da Robustez

   As implementações TCP seguirão um princípio geral de robustez: ser
   conservador em o que você faz, seja liberal em o que você aceita de
   outras.

 [Página 13]
 Setembro de 1981
 protocolo de Controle de Transmissão

 [Página 14]

 Setembro de 1981
                                            protocolo de Controle de Transmissão

                       3. ESPECIFICAÇÃO FUNCIONAL

 3.1 .  Formato de cabeçalho

   Segmentos TCP são enviados como datagramas da Internet.  O protocolo da Internet
   cabeçalho carrega vários campos de informação, incluindo a fonte e
   endereços de host de destino [ 2 ].  Um cabeçalho TCP segue a internet
   cabeçalho, fornecendo informações específicas para o protocolo TCP.  este
   divisão permite a existência de protocolos de nível de host que não sejam
   TCP.

   Formato de cabeçalho TCP

     0 1 2 3
     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
    + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - +
    |  Porto de Origem |  Porto de destino |
    + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - +
    |  Número de Sequência |
    + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - +
    |  Número de Confirmação |
    + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - +
    |  Dados |  | U | A | P | R | S | F |  |
    |  Offset |  Reservado | R | C | S | S | Y | I |  Janela |
    |  |  | G | K | H | T | N | N |  |
    + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - +
    |  Soma de verificação |  Ponteiro Urgente |
    + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - +
    |  Opções |  Preenchimento |
    + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - +
    |  dados |
    + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - +

                             Formato de cabeçalho TCP

           Observe que uma marca de escala representa uma posição de bit.

                                Figura 3.

   Porta de Origem: 16 bits

     O número da porta de origem.

   Porta de Destino: 16 bits

     O número da porta de destino.

 [Página 15]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

   Número de Sequência: 32 bits

     O número sequencial do primeiro octeto de dados neste segmento (exceto
     quando o SYN está presente).  Se SYN estiver presente, o número de sequência é o
     o número de sequência inicial (ISN) e o primeiro octeto de dados é ISN + 1.

   Número de Confirmação: 32 bits

     Se o bit de controle ACK for definido, este campo conterá o valor do
     próximo número de seqüência que o remetente do segmento está esperando
     receber.  Depois que uma conexão é estabelecida, isso sempre é enviado.

   Deslocamento de dados: 4 bits

     O número de palavras de 32 bits no cabeçalho TCP.  Isso indica onde
     os dados começam.  O cabeçalho TCP (mesmo um incluindo opções) é um
     número integral de 32 bits.

   Reservado: 6 bits

     Reservado para uso futuro.  Deve ser zero.

   Bits de controle: 6 bits (da esquerda para a direita):

     URG: Campo Urgente Ponteiro significativo
     ACK: campo de confirmação significativo
     PSH: Push Function
     RST: Redefinir a conexão
     SYN: Sincronizar números de sequência
     FIN: Não há mais dados do remetente

   Janela: 16 bits

     O número de octetos de dados que começam com o indicado no
     campo de reconhecimento que o remetente deste segmento está disposto a
     aceitar.

   Soma de verificação: 16 bits

     O campo checksum é o complemento de 16 bits do seu
     soma complementar de todas as palavras de 16 bits no cabeçalho e texto.  Se um
     segmento contém um número ímpar de octetos de cabeçalho e texto a serem
     checksummed, o último octeto é preenchido à direita com zeros para
     formar uma palavra de 16 bits para fins de checksum.  O pad não é
     transmitido como parte do segmento.  Ao calcular a soma de verificação,
     o próprio campo de soma de verificação é substituído por zeros.

     A soma de verificação também abrange um pseudo cabeçalho de 96 bits conceitualmente

 [Página 16]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional

     prefixado ao cabeçalho TCP.  Este pseudo cabeçalho contém a fonte
     Endereço, o endereço de destino, o protocolo e o comprimento do TCP.
     Isso fornece a proteção TCP contra segmentos não rotulados.  este
     informação é transportada no Protocolo Internet e é transferida
     através da interface TCP / Rede nos argumentos ou resultados de
     chamadas pelo TCP no IP.

                      + -------- + -------- + -------- + -------- +
                      |  Endereço de Origem |
                      + -------- + -------- + -------- + -------- +
                      |  Endereço de Destino |
                      + -------- + -------- + -------- + -------- +
                      |  zero |  PTCL |  Comprimento TCP |
                      + -------- + -------- + -------- + -------- +

       O Comprimento TCP é o comprimento do cabeçalho TCP mais o tamanho dos dados
       octetos (isto não é uma quantidade explicitamente transmitida, mas é
       computado), e não conta os 12 octetos do pseudo
       cabeçalho.

   Ponteiro Urgente: 16 bits

     Este campo comunica o valor atual do ponteiro urgente como um
     desvio positivo do número de sequência neste segmento.  o
     ponteiro urgente aponta para o número de seqüência do octeto seguinte
     os dados urgentes.  Este campo só pode ser interpretado em segmentos com
     o bit de controle URG definido.

   Opções: variável

     As opções podem ocupar espaço no final do cabeçalho TCP e são
     múltiplo de 8 bits de comprimento.  Todas as opções estão incluídas no
     checksum.  Uma opção pode começar em qualquer limite de octetos.  Existem dois
     casos para o formato de uma opção:

       Caso 1: Um único octeto de tipo de opção.

       Caso 2: Um octeto de tipo de opção, um octeto de comprimento de opção e
                os octetos de dados de opções reais.

     O comprimento da opção conta os dois octetos do tipo de opção e
     comprimento da opção, bem como os octetos de dados da opção.

     Observe que a lista de opções pode ser menor que o deslocamento de dados
     campo pode implicar.  O conteúdo do cabeçalho além do
     Opção de fim de opção deve ser preenchimento de cabeçalho (ou seja, zero).

     Um TCP deve implementar todas as opções.

 [Página 17]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

     As opções atualmente definidas incluem (tipo indicado em octal):

       Comprimento do Tipo Significado
       ---- ------ -------
        0 - Fim da lista de opções.
        1 - Sem operação.
        2 4 Tamanho máximo do segmento.

     Definições de opções específicas

       Fim da lista de opções

         + -------- +
         | 00000000 |
         + -------- +
          Kind = 0

         Este código de opção indica o final da lista de opções.  este
         pode não coincidir com o fim do cabeçalho TCP de acordo com
         o campo Deslocamento de dados.  Isso é usado no final de todas as opções,
         não é o fim de cada opção, e só precisa ser usado se o final de cada
         as opções não coincidiriam com o fim do TCP
         cabeçalho.

       Nenhuma operação

         + -------- +
         | 00000001 |
         + -------- +
          Kind = 1

         Este código de opção pode ser usado entre opções, por exemplo, para
         Alinhar o início de uma opção subseqüente em um limite de palavra.
         Não há garantia de que os remetentes usarão essa opção,
         receptores devem estar preparados para processar opções, mesmo que
         não começa em um limite de palavra.

       Tamanho máximo do segmento

         + -------- + -------- + --------- + -------- +
         | 00000010 | 00000100 |  tamanho max seg |
         + -------- + -------- + --------- + -------- +
          Tipo = 2 Comprimento = 4


 [Página 18]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional

         Dados da Opção de Tamanho Máximo do Segmento: 16 bits

           Se esta opção estiver presente, comunica o valor máximo
           recebe o tamanho do segmento no TCP que envia este segmento.
           Este campo só deve ser enviado no pedido de conexão inicial
           (isto é, em segmentos com o conjunto de bits de controle SYN).  Se este
           opção não é usada, qualquer tamanho de segmento é permitido.

   Preenchimento: variável

     O preenchimento do cabeçalho TCP é usado para garantir que o cabeçalho TCP termine
     e os dados começam em um limite de 32 bits.  O preenchimento é composto de
     zeros.

 3.2 .  Terminologia

   Antes de podermos discutir muito sobre o funcionamento do TCP, precisamos
   para introduzir alguma terminologia detalhada.  A manutenção de um TCP
   conexão requer a lembrança de várias variáveis.  Nós concebemos
   dessas variáveis ​​sendo armazenadas em um registro de conexão chamado de
   Bloco de Controle de Transmissão ou TCB.  Entre as variáveis ​​armazenadas no
   TCB são os números de tomadas locais e remotas, a segurança e
   precedência da conexão, ponteiros para o usuário enviar e receber
   buffers, ponteiros para a fila de retransmissão e para o segmento atual.
   Além disso, diversas variáveis ​​relacionadas ao envio e recebimento
   números de seqüência são armazenados no TCB.

     Enviar variáveis ​​de seqüência

       SND.UNA - enviar não reconhecido
       SND.NXT - enviar próximo
       SND.WND - enviar janela
       SND.UP - envia um ponteiro urgente
       SND.WL1 - número de sequência do segmento usado na última atualização da janela
       SND.WL2 - número de reconhecimento de segmento usado na última janela
                 atualizar
       ISS - número de sequência inicial de envio

     Receber Variáveis ​​de Sequência

       RCV.NXT - receba em seguida
       RCV.WND - janela de recebimento
       RCV.UP - recebe um ponteiro urgente
       IRS - número inicial de sequência de recepção

 [Página 19]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

   Os diagramas a seguir podem ajudar a relacionar algumas dessas variáveis
   o espaço da sequência.

   Enviar espaço de seqüência

                    1 2 3 4
               ---------- | ---------- | ---------- | ----------
                      SND.UNA SND.NXT SND.UNA
                                           + SND.WND

         1 - antigos números de sequência que foram reconhecidos
         2 - números de sequência de dados não reconhecidos
         3 - números de sequência permitidos para nova transmissão de dados
         4 - números de seqüência futuros que ainda não são permitidos

                           Enviar espaço de seqüência

                                Figura 4

   A janela de envio é a parte do espaço de seqüência rotulado como
   figura 4.

   Receber espaço de seqüência

                        1 2 3
                    ---------- | ---------- | ----------
                           RCV.NXT RCV.NXT
                                     + RCV.WND

         1 - antigos números de sequência que foram reconhecidos
         2 - números de sequência permitidos para nova recepção
         3 - números de seqüência futuros que ainda não são permitidos

                          Receber espaço de seqüência

                                Figura 5

   A janela de recepção é a parte do espaço da sequência rotulada 2 em
   figura 5.

   Existem também algumas variáveis ​​usadas freqüentemente na discussão que
   pegue seus valores dos campos do segmento atual.

 [Página 20]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional

     Variáveis ​​do segmento atual

       SEG.SEQ - número de sequência do segmento
       SEG.ACK - número de reconhecimento do segmento
       SEG.LEN - comprimento do segmento
       SEG.WND - janela de segmento
       SEG.UP - ponteiro urgente do segmento
       SEG.PRC - valor de precedência do segmento

   Uma conexão avança por uma série de estados durante sua
   tempo de vida.  Os estados são: LISTEN, SYN-SENT, SYN-RECEIVED,
   ESTABELECIDO, FIN-WAIT-1, FIN-WAIT-2, CLOSE-WAIT, FECHADO, LAST-ACK,
   TEMPO DE ESPERA e o estado fictício FECHADO.  FECHADO é fictício
   porque representa o estado quando não há TCB e, portanto,
   sem conexão.  Resumidamente, os significados dos estados são:

     LISTEN - representa a espera por uma solicitação de conexão de qualquer controle remoto
     TCP e porta.

     SYN-SENT - representa a espera por uma solicitação de conexão correspondente
     depois de ter enviado um pedido de ligação.

     SYN RECEIVED - representa a espera por uma conexão de confirmação
     solicitar o reconhecimento depois de ter recebido e enviado um
     pedido de conexão.

     ESTABELECIDO - representa uma conexão aberta, os dados recebidos podem ser
     entregue ao usuário.  O estado normal da fase de transferência de dados
     da conexão.

     FIN-WAIT-1 - representa a espera por uma solicitação de término de conexão
     a partir do TCP remoto, ou um reconhecimento da conexão
     solicitação de rescisão enviada anteriormente.

     FIN-WAIT-2 - representa a espera por uma solicitação de término de conexão
     do TCP remoto.

     CLOSE-WAIT - representa a espera por uma solicitação de término de conexão
     do usuário local.

     CLOSING - representa a espera por uma solicitação de término de conexão
     confirmação do TCP remoto.

     LAST-ACK - representa aguardar um reconhecimento do
     pedido de terminação de conexão enviado anteriormente ao TCP remoto
     (que inclui um reconhecimento de sua conexão
     pedido).

 [Página 21]

 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

     TIME-WAIT - representa esperar o tempo suficiente para passar para ter certeza
     o TCP remoto recebeu o reconhecimento de sua conexão
     pedido de rescisão.

     FECHADO - não representa nenhum estado de conexão.

   Uma conexão TCP progride de um estado para outro em resposta a
   eventos.  Os eventos são as chamadas do usuário, OPEN, SEND, RECEIVE, CLOSE,
   ABORTAR E STATUS;  os segmentos de entrada, particularmente aqueles
   contendo as bandeiras SYN, ACK, RST e FIN;  e tempos limite.

   O diagrama de estados da figura 6 ilustra apenas as mudanças de estado, juntas
   com os eventos causadores e ações resultantes, mas não aborda
   condições de erro ou ações que não estão conectadas com o estado
   alterar.  Em uma seção posterior, mais detalhes são oferecidos com relação a
   a reação do TCP aos eventos.

   NOTA BENE: este diagrama é apenas um resumo e não deve ser tomado como
   a especificação total.

 [Página 22]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional


                               + --------- + --------- \ ativo OPEN
                               |  FECHADO |  \ -----------
                               + --------- + <--------- \ \ create TCB
                                 |  ^ \ \ snd SYN
                    passivo OPEN |  |  FECHAR \ \
                    ------------ |  |  ---------- \ \
                     criar TCB |  |  excluir TCB \ \
                                 V |  \ \
                               + --------- + FECHAR |  \
                               |  ESCUTE |  ---------- |  |
                               + --------- + excluir TCB |  |
                    rcv SYN |  |  ENVIAR |  |
                   ----------- |  |  ------- |  V
  + --------- + snd SYN, ACK / \ snd SYN + --------- +
  |  | <----------------- ------------------> |  |
  |  SYN |  rcv SYN |  SYN |
  |  RCVD | <----------------------------------------------- |  SENT |
  |  |  e ACK |  |
  |  | ------------------ ------------------- |  |
  + --------- + rcv ACK de SYN \ / rcv SYN, ACK + --------- +
    |  -------------- |  |  -----------
    |  x |  |  e ACK
    |  VV
    |  CLOSE + --------- +
    |  ------- |  ESTAB |
    |  snd FIN + --------- +
    |  FECHAR |  |  rcv FIN
    V ------- |  |  -------
  + --------- + snd FIN / \ snd ACK + --------- +
  |  FIN | <----------------- ------------------> |  FECHAR |
  |  WAIT-1 | ------------------ |  ESPERA |
  + --------- + rcv FIN \ + --------- +
    |  rcv ACK de FIN ------- |  FECHAR |
    |  -------------- snd ACK |  ------- |
    V x V e FIN V
  + --------- + + --------- + + --------- +
  | FINWAIT-2 |  |  ENCERRAMENTO |  |  LAST-ACK |
  + --------- + + --------- + + --------- +
    |  rcv ACK de FIN |  rcv ACK de FIN |
    |  rcv FIN -------------- |  Tempo limite = 2MSL -------------- |
    |  ------- x V ------------ x V
     \ snd ACK + --------- + excluir TCB + --------- +
      ------------------------> | TIME WAIT | ------------------> |  FECHADO |
                               + --------- + + --------- +

                       Diagrama do estado de conexão TCP
                                Figura 6

 [Página 23]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

 3.3 .  Números de sequência

   Uma noção fundamental no design é que todo octeto de dados enviado
   sobre uma conexão TCP tem um número de seqüência.  Como todo octeto é
   sequenciados, cada um deles pode ser reconhecido.  O reconhecimento
   mecanismo empregado é cumulativo para que um reconhecimento de seqüência
   número X indica que todos os octetos até, mas não incluindo X, foram
   recebido.  Este mecanismo permite a duplicação direta
   detecção na presença de retransmissão.  Numeração de octetos
   dentro de um segmento é que o primeiro octeto de dados imediatamente após
   o cabeçalho é o mais baixo numerado, e os seguintes octetos são
   numeradas consecutivamente.

   É essencial lembrar que o espaço real do número de seqüência é
   finito, embora muito grande.  Este espaço varia de 0 a 2 ** 32 - 1.
   Como o espaço é finito, toda a aritmética lida com a sequência
   números devem ser realizados módulo 2 ** 32.  Esta aritmética sem sinal
   preserva o relacionamento dos números de sequência à medida que eles
   2 ** 32 - 1 a 0 novamente.  Existem algumas sutilezas para o módulo do computador
   aritmética, tão grande cuidado deve ser tomado na programação do
   comparação de tais valores.  O símbolo "= <" significa "menor que ou igual"
   (módulo 2 ** 32).

   Os tipos típicos de comparações de números de seqüência que o TCP deve
   executar incluem:

     (a) Determinar que uma confirmação se refere a alguma sequência
          número enviado mas ainda não confirmado.

     (b) Determinar que todos os números de sequência ocupados por um segmento
          foram reconhecidos (por exemplo, para remover o segmento de um
          fila de retransmissão).

     (c) Determinar que um segmento de entrada contém números de sequência
          que são esperados (ou seja, que o segmento "sobrepõe" o
          receber janela).

 [Página 24]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional

   Em resposta ao envio de dados, o TCP receberá confirmações.  o
   as seguintes comparações são necessárias para processar os agradecimentos.

     SND.UNA = número de sequência não reconhecido mais antigo

     SND.NXT = próximo número de seqüência a ser enviado

     SEG.ACK = reconhecimento do TCP receptor (próxima seqüência
               número esperado pelo TCP receptor

     SEG.SEQ = primeiro número de sequência de um segmento

     SEG.LEN = o número de octetos ocupados pelos dados no segmento
               (contando SYN e FIN)

     SEG.SEQ + SEG.LEN-1 = último número de sequência de um segmento

   Um novo reconhecimento (chamado de "ack aceitável") é aquele para o qual
   a desigualdade abaixo é válida:

     SND.UNA <SEG.ACK = <SND.NXT

   Um segmento na fila de retransmissão é totalmente reconhecido se a soma
   de seu número de seqüência e comprimento é menor ou igual que o
   valor de confirmação no segmento de entrada.

   Quando os dados são recebidos, as seguintes comparações são necessárias:

     RCV.NXT = próximo número de sequência esperado em um segmento de entrada e
         é a borda esquerda ou inferior da janela de recebimento

     RCV.NXT + RCV.WND-1 = último número de sequência esperado em uma entrada
         segmento e é a borda direita ou superior da janela de recebimento

     SEG.SEQ = primeiro número de seqüência ocupado pelo segmento de entrada

     SEG.SEQ + SEG.LEN-1 = último número de sequência ocupado pela entrada
         segmento

   Um segmento é julgado por ocupar uma parte da sequência de recebimento válida
   espaço se

     RCV.NXT = <SEG.SEQ <RCV.NXT + RCV.WND

   ou

     RCV.NXT = <SEG.SEQ + SEG.LEN-1 <RCV.NXT + RCV.WND

 [Página 25]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

   A primeira parte deste teste verifica se o início do teste
   segmento cai na janela, a segunda parte do teste verifica para ver
   se o final do segmento cair na janela;  se o segmento passar
   qualquer parte do teste contém dados na janela.

   Na verdade, é um pouco mais complicado do que isso.  Devido a zero
   janelas e segmentos de comprimento zero, temos quatro casos para o
   aceitabilidade de um segmento de entrada:

     Teste de recebimento de segmento
     Janela Comprimento
     ------- ------- ------------------------------------ -------
        0 0 SEG.SEQ = RCV.NXT

        0> 0 RCV.NXT = <SEG.SEQ <RCV.NXT + RCV.WND

       > 0 0 não aceitável

       > 0> 0 RCV.NXT = <SEG.SEQ <RCV.NXT + RCV.WND
                   ou RCV.NXT = <SEG.SEQ + SEG.LEN-1 <RCV.NXT + RCV.WND

   Note que quando a janela de recepção é zero, nenhum segmento deve ser
   aceitável, exceto segmentos ACK.  Assim, é possível que um TCP
   manter uma janela de recepção zero ao transmitir dados e receber
   ACKs.  No entanto, mesmo quando a janela de recepção é zero, um TCP deve
   processa os campos RST e URG de todos os segmentos de entrada.

   Aproveitamos o esquema de numeração para proteger certas
   controle de informações também.  Isto é conseguido implicitamente incluindo
   alguns sinalizadores de controle no espaço de seqüência para que possam ser retransmitidos
   e reconhecido sem confusão (ou seja, uma e apenas uma cópia do
   o controle será resolvido).  Informações de controle não são fisicamente
   transportado no espaço de dados do segmento.  Consequentemente, devemos adotar regras
   para atribuir implicitamente números de sequência ao controle.  O SYN e o FIN
   são os únicos controles que exigem essa proteção, e esses controles
   são usados ​​apenas na abertura e fechamento da conexão.  Para o número de sequência
   fins, o SYN é considerado como ocorrendo antes dos primeiros dados reais
   octeto do segmento em que ocorre, enquanto o FIN é considerado
   ocorrer após o último octeto de dados reais em um segmento em que
   ocorre.  O comprimento do segmento (SEG.LEN) inclui dados e sequência
   espaço ocupando controles.  Quando um SYN está presente, o SEG.SEQ é o
   número de sequência do SYN.

 [Página 26]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional

   Seleção do Número de Sequência Inicial

   O protocolo não coloca nenhuma restrição em uma conexão particular sendo
   usado repetidamente.  Uma conexão é definida por um par de
   tomadas.  Novas instâncias de uma conexão serão referidas como
   encarnações da conexão.  O problema que surge disso é
   - "como o TCP identifica segmentos duplicados de anteriores
   encarnações da conexão? "Esse problema se torna aparente se o
   a conexão está sendo aberta e fechada em rápida sucessão, ou se o
   a conexão se rompe com a perda de memória e, em seguida, é restabelecida.

   Para evitar confusão, devemos evitar segmentos de uma encarnação de um
   conexão de ser usado enquanto os mesmos números de sequência ainda podem
   estar presente na rede a partir de uma encarnação anterior.  Nos queremos
   garantir isso, mesmo se um TCP falhar e perder todo o conhecimento do
   números de sequência que está sendo usado.  Quando novas conexões são criadas,
   um gerador de número de seqüência inicial (ISN) é empregado, que seleciona
   novo ISN de 32 bits.  O gerador está ligado a um (possivelmente fictício) 32
   relógio de bit cujo bit de baixa ordem é incrementado aproximadamente a cada 4
   microssegundos.  Assim, o ISN circula aproximadamente a cada 4,55 horas.
   Como assumimos que os segmentos permanecerão na rede não mais do que
   o tempo máximo de vida do segmento (MSL) e que o MSL é inferior a 4,55
   horas podemos supor razoavelmente que as ISNs serão únicas.

   Para cada conexão existe um número sequencial de envio e um
   número sequencial.  O número inicial de sequência de envio (ISS) é escolhido por
   os dados que enviam TCP, e o número inicial de seqüência de recepção (IRS) é
   aprendido durante a conexão estabelecendo o procedimento.

   Para uma conexão ser estabelecida ou inicializada, os dois TCPs devem
   sincronizar os números de seqüência inicial um do outro.  Isso é feito em
   uma troca de conexão estabelecendo segmentos carregando um bit de controle
   chamado "SYN" (para sincronizar) e os números de seqüência inicial.  Como um
   De forma abreviada, os segmentos que transportam o bit SYN são também chamados de "SYNs".
   Assim, a solução requer um mecanismo adequado para escolher um
   número de seqüência inicial e um aperto de mão ligeiramente envolvido para trocar
   os ISNs.

   A sincronização requer que cada lado envie sua própria inicial
   número de sequência e para receber uma confirmação do mesmo em confirmação
   do outro lado.  Cada lado também deve receber o outro lado
   número de seqüência inicial e enviar uma confirmação de confirmação.

     1) A -> B SYN meu número sequencial é X
     2) A <- B ACK seu número de seqüência é X
     3) A <- B SYN meu número de sequência é Y
     4) A -> B ACK seu número de sequência é Y

 [Página 27]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

   Como as etapas 2 e 3 podem ser combinadas em uma única mensagem, isso é
   chamou o aperto de mão de três vias (ou três mensagens).

   Um aperto de mão de três vias é necessário porque os números de seqüência não são
   ligados a um relógio global na rede, e os TCPs podem ter diferentes
   mecanismos para escolher os ISN's.  O receptor do primeiro SYN tem
   nenhuma maneira de saber se o segmento era um antigo atrasado ou não,
   a menos que se lembre do último número de seqüência usado na conexão
   (o que nem sempre é possível), e por isso deve pedir ao remetente para
   verifique este SYN.  O aperto de mão de três maneiras e as vantagens de um
   esquema acionado por relógio são discutidos em [ 3 ].

   Sabendo quando ficar quieto

   Para ter certeza de que um TCP não cria um segmento que carrega um
   número de sequência que pode ser duplicado por um segmento antigo restante
   a rede, o TCP deve manter-se em silêncio por uma vida útil máxima do segmento
   (MSL) antes de atribuir qualquer número de seqüência ao inicializar ou
   recuperando-se de um acidente no qual a memória de números de sequência em uso era
   perdido.  Para esta especificação, o MSL é considerado como sendo de 2 minutos.  este
   é uma opção de engenharia e pode ser alterada se a experiência indicar
   é desejável fazê-lo.  Note que se um TCP for reinicializado em algum
   sentido, ainda mantém a sua memória de números de seqüência em uso, então ele precisa
   não espere nada;  só deve ter certeza de usar números de seqüência maiores
   do que os usados ​​recentemente.

   O conceito de tempo silencioso do TCP

     Esta especificação fornece que hosts que "travam" sem
     reter qualquer conhecimento dos últimos números de sequência transmitidos
     cada conexão ativa (ou seja, não fechada) deve atrasar a emissão de
     Segmentos TCP para, pelo menos, o tempo máximo de vida do segmento (MSL) acordado
     no sistema de internet do qual o host faz parte.  No
     parágrafos abaixo, é dada uma explicação para esta especificação.
     Implementadores TCP podem violar a restrição de "tempo de espera", mas apenas
     correndo o risco de fazer com que alguns dados antigos sejam aceitos como novos ou novos
     dados rejeitados como antigos duplicados por alguns receptores na internet
     sistema.

     Os TCPs consomem espaço numérico de seqüência cada vez que um segmento é formado e
     entrou na fila de saída da rede em um host de origem.  o
     detecção duplicada e algoritmo de sequenciamento no protocolo TCP
     depende da ligação única de dados do segmento para sequenciar o espaço para
     na medida em que os números de seqüência não percorrerão todos os 2 ** 32
     valores antes que os dados do segmento ligados a esses números de sequência tenham
     foi entregue e reconhecido pelo receptor e todos os duplicados
     cópias dos segmentos foram "drenados" da internet.  Sem
     tal suposição, dois segmentos TCP distintos poderiam ser concebivelmente

 [Página 28]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional

     atribuídos os mesmos ou números de sequência sobrepostos, causando confusão
     no receptor como quais dados são novos e quais são antigos.  Lembrar
     que cada segmento está ligado a tantos números sequenciais consecutivos
     como existem octetos de dados no segmento.

     Em condições normais, os TCPs acompanham o próximo número de sequência
     para emitir e o mais antigo aguardando confirmação, a fim de evitar
     erroneamente usando um número de seqüência antes de seu primeiro uso tem
     foi reconhecido.  Isso por si só não garante que duplicatas antigas
     dados são drenados da rede, então o espaço de seqüência foi feito
     muito grande para reduzir a probabilidade de que uma duplicata errante
     causar problemas na chegada.  Em 2 megabits / seg.  demora 4,5 horas
     para usar 2 ** 32 octetos de espaço de sequência.  Desde o segmento máximo
     vida útil na rede não é susceptível de exceder algumas dezenas de segundos,
     isto é considerado uma ampla proteção para redes previsíveis, mesmo se os dados
     as taxas aumentam para l0s de megabits / seg.  Em 100 megabits / seg, o
     tempo de ciclo é de 5,4 minutos, o que pode ser um pouco curto, mas ainda
     dentro da razão.

     O algoritmo básico de detecção e sequenciamento duplicado no TCP pode ser
     derrotado, no entanto, se uma fonte TCP não tiver qualquer memória do
     números de sequência usados ​​por último em uma determinada conexão.  Por exemplo, se
     o TCP deveria iniciar todas as conexões com o número de seqüência 0, então
     ao travar e reiniciar, um TCP pode reformar um
     conexão (possivelmente após a resolução de conexão semiaberta) e
     pacotes com números de sequência idênticos ou sobrepostos com
     pacotes ainda na rede que foram emitidos em um anterior
     encarnação da mesma conexão.  Na ausência de conhecimento
     sobre os números de seqüência usados ​​em uma conexão específica, o TCP
     especificação recomenda que o atraso de origem para segundos MSL
     antes de emitir segmentos na conexão, para dar tempo
     segmentos da encarnação ligação anterior para drenar a partir do
     sistema.

     Mesmo hosts que podem lembrar a hora do dia e usaram para selecionar
     os valores do número de sequência inicial não estão imunes a este problema
     (ou seja, mesmo se a hora do dia for usada para selecionar uma sequência inicial
     número para cada nova encarnação de conexão).

     Suponha, por exemplo, que uma conexão seja aberta a partir de
     número de seqüência S. Suponha que esta conexão não seja muito usada
     e que, eventualmente, a função de número de sequência inicial (ISN (t))
     assume um valor igual ao número de sequência, digamos S1, do último
     segmento enviado por este TCP em uma conexão particular.  Agora suponha que
     Neste instante, o host trava, recupera e estabelece um novo
     encarnação da conexão.  O número de sequência inicial escolhido é
     S1 = ISN (t) - último número de sequência usado na antiga encarnação de
     conexão!  Se a recuperação ocorrer com rapidez suficiente, qualquer

 [Página 29]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

     duplicatas nos números de seqüência de rolamento da rede na vizinhança
     de S1 pode chegar e ser tratado como novos pacotes pelo receptor de
     a nova encarnação da conexão.

     O problema é que o host em recuperação pode não saber por quanto tempo
     caiu nem sabe se ainda há duplicatas antigas em
     o sistema de encarnações de conexão anteriores.

     Uma maneira de lidar com esse problema é atrasar deliberadamente
     segmentos para um MSL após a recuperação de um acidente, este é o "bastante
     tempo ". Hosts que preferem evitar a espera são
     dispostos a arriscar possíveis confusões de pacotes antigos e novos em um dado
     destino pode optar por não esperar pelo "tempo".
     Os implementadores podem fornecer aos usuários TCP a capacidade de selecionar
     conexão por base de conexão se deve esperar após um acidente, ou pode
     implementar informalmente o "bastante tempo" para todas as conexões.
     Obviamente, mesmo quando um usuário escolhe "esperar", isso não é
     necessário após o host estar "ativo" por pelo menos segundos MSL.

     Para resumir: todo segmento emitido ocupa uma ou mais seqüências
     números no espaço de seqüência, os números ocupados por um segmento são
     "ocupado" ou "em uso" até que os segundos MSL tenham passado, ao travar um
     bloco de espaço-tempo é ocupado pelos octetos do último emitido
     segmento, se uma nova conexão é iniciada muito cedo e usa qualquer um dos
     números de seqüência no espaço-tempo pegada do último segmento de
     a encarnação conexão anterior, há uma seqüência potencial
     número de área de sobreposição que poderia causar confusão no receptor.

 3.4 .  Estabelecendo uma conexão

   O "handshake de três vias" é o procedimento usado para estabelecer
   conexão.  Este procedimento normalmente é iniciado por um TCP e
   respondido por outro TCP.  O procedimento também funciona se dois TCP
   inicie simultaneamente o procedimento.  Quando tentativa simultânea
   ocorre, cada TCP recebe um segmento "SYN" que não carrega
   confirmação após ter enviado um "SYN".  Claro, a chegada de
   um antigo segmento "SYN" duplicado pode potencialmente fazer com que ele pareça
   destinatário, que um início de conexão simultânea está em andamento.
   O uso adequado de segmentos "redefinidos" pode desambiguar esses casos.

   Vários exemplos de iniciação de conexão seguem.  Embora estes
   exemplos não mostram a sincronização de conexão usando dados
   segmentos, isso é perfeitamente legítimo, desde que o TCP receptor
   não entrega os dados ao usuário até que fique claro que os dados estão
   válidos (ou seja, os dados devem ser armazenados no receptor até que
   conexão atinge o estado ESTABLISHED).  O aperto de mão de três vias
   reduz a possibilidade de conexões falsas.  É o

 [Página 30]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional

   implementação de um trade-off entre memória e mensagens para fornecer
   informações para esta verificação.

   O aperto de mão de três vias mais simples é mostrado na figura 7 abaixo.  o
   As figuras devem ser interpretadas da seguinte maneira.  Cada linha é
   numerado para fins de referência.  Setas direitas (->) indicam
   partida de um segmento TCP do TCP A para o TCP B, ou a chegada de um
   segmento em B de A. Esquerda setas (<-), indicam o inverso.
   Reticências (...) indicam um segmento que ainda está na rede
   (atrasado).  Um "XXX" indica um segmento perdido ou rejeitado.
   Comentários aparecem entre parênteses.  Estados TCP representam o estado APÓS
   a partida ou chegada do segmento (cujo conteúdo é mostrado em
   o centro de cada linha).  O conteúdo do segmento é mostrado em abreviado
   formulário, com número de seqüência, sinalizadores de controle e campo ACK.  De outros
   campos como janela, endereços, comprimentos e texto foram omitidos
   no interesse da clareza.

       TCP A TCP B

   1. FECHADO OUVIR

   2. SYN-SENT -> <SEQ = 100> <CTL = SYN> -> SYN RECEBIDO

   3. ESTABELECIDO <- <SEQ = 300> <ACK = 101> <CTL = SYN, ACK> <- SYN RECEBIDO

   4. ESTABELECIDO -> <SEQ = 101> <ACK = 301> <CTL = ACK> -> ESTABELECIDO

   5. ESTABELECIDO -> <SEQ = 101> <ACK = 301> <CTL = ACK> <DADOS> -> ESTABELECIDO

           Aperto de mão de 3 vias básico para sincronização de conexão

                                 Figura 7

   Na linha 2 da figura 7, o TCP A começa enviando um segmento SYN
   indicando que usará números de sequência começando com sequência
   número 100. Na linha 3, o TCP B envia um SYN e reconhece o SYN
   recebido do TCP A. Observe que o campo de confirmação indica que o TCP
   B agora está esperando ouvir a seqüência 101, reconhecendo o SYN que
   sequência ocupada 100.

   Na linha 4, o TCP A responde com um segmento vazio contendo um ACK para
   SYN do TCP B;  e na linha 5, o TCP A envia alguns dados.  Note que o
   número de sequência do segmento na linha 5 é o mesmo da linha 4
   porque o ACK não ocupa espaço numérico de seqüência (se isso acontecesse, nós
   acabaria ACK ACK's!).

 [Página 31]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

   A iniciação simultânea é apenas um pouco mais complexa, como é mostrado
   figura 8. Cada TCP passa de CLOSED para SYN-SENT para SYN-RECEIVED para
   ESTABELECIDO

       TCP A TCP B

   1. FECHADO FECHADO

   2. SYN-SENT -> <SEQ = 100> <CTL = SYN> ...

   3. SIN RECEBIDO <- <SEQ = 300> <CTL = SYN> <- SYN-SENT

   4. ... <SEQ = 100> <CTL = SYN> -> SYN RECEBIDO

   5. SIN RECEBIDO -> <SEQ = 100> <ACK = 301> <CTL = SYN, ACK> ...

   6. ESTABELECIDO <- <SEQ = 300> <ACK = 101> <CTL = SYN, ACK> <- SYN RECEBIDO

   7. ... <SEQ = 101> <ACK = 301> <CTL = ACK> -> ESTABELECIDO

                 Sincronização de Conexão Simultânea

                                Figura 8.

   A principal razão para o aperto de mão de três vias é evitar
   iniciações de conexão duplicadas causam confusão.  Lidar com
   isso, uma mensagem de controle especial, reset, foi planejada.  Se o
   receber TCP está em um estado não-sincronizado (ou seja, SYN-SENT,
   SYN-RECEIVED), retorna a LISTEN ao receber um reset aceitável.
   Se o TCP estiver em um dos estados sincronizados (ESTABLISHED,
   FIN-WAIT-1, FIN-WAIT-2, CLOSE-WAIT, FECHAMENTO, LESTE-ACK, TIME-WAIT),
   aborta a conexão e informa seu usuário.  Nós discutimos este último
   caso sob conexões "abertas pela metade" abaixo.

 [Página 32]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional


       TCP A TCP B

   1. FECHADO OUVIR

   2. SYN-SENT -> <SEQ = 100> <CTL = SYN> ...

   3. (duplicado) ... <CTL = SYN> -> SYN RECEBIDO

   4. SYN-SENT <- <= <300> <ACK = 91> <CTL = SYN, ACK> <- SYN RECEBIDO

   5. SYN-SENT -> <SEQ = 91> <CTL = RST> -> OUVIR


   6. ... <CTRL = SYN> -> SYN RECEBIDO

   7. SYN-SENT <- <SEQ = 400> <ACK = 101> <CTL = SYN, ACK> <- SYN RECEBIDO

   8. ESTABELECIDO -> <SEQ = 101> <ACK = 401> <CTL = ACK> -> ESTABELECIDO

                     Recuperação de SYN Duplicado Antigo
                                Figura 9

   Como um exemplo simples de recuperação de duplicatas antigas, considere
   figura 9. Na linha 3, um duplicado antigo SYN chega ao TCP B. TCP B
   não posso dizer que esta é uma duplicata antiga, por isso responde normalmente
   (linha 4).  TCP A detecta que o campo ACK está incorreto e retorna um
   RST (reset) com seu campo SEQ selecionado para fazer o segmento
   crível.  O TCP B, ao receber o RST, retorna ao estado LISTEN.
   Quando o SYN original (trocadilho intencional) finalmente chega à linha 6, o
   a sincronização prossegue normalmente.  Se o SYN na linha 6 tivesse chegado
   antes do RST, uma troca mais complexa poderia ter ocorrido com o RST
   enviado em ambas as direções.

   Conexões semiabertas e outras anomalias

   Uma conexão estabelecida é considerada "semi-aberta" se uma das
   Os TCPs fecharam ou cancelaram a conexão em seu final sem o
   conhecimento do outro, ou se as duas extremidades da conexão tiverem
   tornar-se dessincronizado devido a um acidente que resultou na perda de
   memória.  Essas conexões serão automaticamente redefinidas se um
   É feita uma tentativa de enviar dados em qualquer direção.  No entanto, meio aberto
   Espera-se que as conexões sejam incomuns, e o procedimento de recuperação
   levemente envolvido.

   Se no site A a conexão não existir mais, então uma tentativa do

 [Página 33]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

   usuário no site B para enviar quaisquer dados nele resultará no site B TCP
   recebendo uma mensagem de controle de redefinição.  Tal mensagem indica ao
   site B TCP que algo está errado, e espera-se abortar o
   conexão.

   Suponha que dois processos de usuário A e B estejam se comunicando com um
   outra quando ocorre uma falha causando perda de memória para o TCP de A.
   Dependendo do sistema operacional que suporta o TCP de A, é provável
   que existe algum mecanismo de recuperação de erro.  Quando o TCP estiver ativo novamente,
   A é provável que comece de novo desde o início ou de uma recuperação
   ponto.  Como resultado, A provavelmente tentará ABRIR a conexão novamente
   ou tente ENVIAR na conexão que acredita estar aberta.  No ultimo
   caso, recebe a mensagem de erro "conexão não aberta" do
   TCP local (A's).  Na tentativa de estabelecer a conexão, o TCP de A
   enviará um segmento contendo SYN.  Esse cenário leva ao
   exemplo mostrado na figura 10. Depois que o TCP A falha, o usuário tenta
   reabra a conexão.  TCP B, entretanto, acha que a conexão
   está aberto.

       TCP A TCP B

   1. (CRASH) (envie 300, receba 100)

   2. FECHADO ESTABELECIDO

   3. SYN-SENT -> <SEQ = 400> <CTL = SYN> -> (??)

   4. (!!) <- <SEQ = 300> <ACK = 100> <CTL = ACK> <- ESTABELECIDO

   5. SYN-SENT -> <SEQ = 100> <CTL = RST> -> (Abortar !!)

   6. SYN-SENT FECHADO

   7. SYN-SENT -> <SEQ = 400> <CTL = SYN> ->

                      Descoberta de conexão semiaberta
                                Figura 10

   Quando o SYN chega na linha 3, TCP B, estando em um estado sincronizado,
   e o segmento de entrada fora da janela, responde com um
   reconhecimento indicando qual a seqüência que ele espera ouvir (ACK
   100).  TCP A vê que este segmento não reconhece nada
   enviado e, sendo não sincronizado, envia um reset (RST) porque tem
   detectou uma conexão semiaberta.  TCP B aborta na linha 5. TCP A vai

 [Página 34]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional

   continue tentando estabelecer a conexão;  o problema é agora
   reduzido ao aperto de mão básico de 3 vias da figura 7.

   Um caso alternativo interessante ocorre quando o TCP A falha e o TCP B
   tenta enviar dados sobre o que pensa ser uma conexão sincronizada.
   Isto é ilustrado na figura 11. Neste caso, os dados que chegam
   TCP A do TCP B (linha 2) é inaceitável porque não existe tal conexão
   existe, então o TCP A envia um RST.  O RST é aceitável, então o TCP B
   processa e aborta a conexão.

         TCP A TCP B

   1. (CRASH) (envie 300, receba 100)

   2. (??) <- <SEQ = 300> <ACK = 100> <DADOS = 10> <CTL = ACK> <- ESTABELECIDO

   3. -> <SEQ = 100> <CTL = RST> -> (ABORT !!)

            Lado ativo causa descoberta de conexão semiaberta

                                Figura 11

   Na figura 12, encontramos os dois TCPs A e B com conexões passivas
   esperando por SYN.  Um duplicado antigo chegando ao TCP B (linha 2) agita B
   em ação.  Um SYN-ACK é retornado (linha 3) e faz com que o TCP A seja
   gerar um RST (o ACK na linha 3 não é aceitável).  TCP B aceita
   o reset e retorna ao seu estado LISTEN passivo.

       TCP A TCP B

   1. ESCUTE ESCUTAR

   2. ... <CTL = SYN> -> SYN RECEBIDO

   3. (??) <- <SEQ = X> <ACK = Z + 1> <CTL = SYN, ACK> <- SYN RECEBIDO

   4. -> <SEQ = Z + 1> <CTL = RST> -> (retorne para LISTEN!)

   5. ESCUTE ESCUTAR

        SYN duplicado antigo inicia uma redefinição em dois soquetes passivos

                                Figura 12
 [Página 35]

 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

   Uma variedade de outros casos são possíveis, todos eles são contabilizados
   pelas seguintes regras para geração e processamento de RST.

   Redefinir Geração

   Como regra geral, o reset (RST) deve ser enviado sempre que um segmento chegar
   que aparentemente não é destinado para a conexão atual.  Estão prontos
   não deve ser enviado se não estiver claro que este é o caso.

   Existem três grupos de estados:

     1. Se a conexão não existir (FECHADO), então uma redefinição é enviada
     em resposta a qualquer segmento recebido, exceto outra reinicialização.  Dentro
     Em particular, os SYNs endereçados a uma conexão inexistente são rejeitados
     por estes meios.

     Se o segmento de entrada tiver um campo ACK, a reconfiguração
     número de sequência do campo ACK do segmento, caso contrário, o
     reset tem número de seqüência zero e o campo ACK é definido como a soma
     do número de seqüência e comprimento do segmento do segmento de entrada.
     A conexão permanece no estado CLOSED.

     2. Se a conexão estiver em um estado não sincronizado (LISTEN,
     SYN-SENT, SYN-RECEIVED), e o segmento de entrada reconhece
     algo ainda não enviado (o segmento carrega um ACK inaceitável) ou
     se um segmento de entrada tiver um nível ou compartimento de segurança
     não corresponde exatamente ao nível e ao compartimento solicitados
     conexão, um reset é enviado.

     Se o nosso SYN não tiver sido reconhecido e o nível de precedência do
     segmento de entrada é maior que o nível de precedência solicitado
     elevar o nível de precedência local (se permitido pelo usuário e
     o sistema) ou enviar um reset;  ou se o nível de precedência do
     segmento de entrada é menor que o nível de precedência solicitado
     continuar como se a precedência fosse exatamente igual (se o TCP remoto
     não pode elevar o nível de precedência para coincidir com o nosso isso será
     detectado no próximo segmento que ele envia, e a conexão será
     terminado então).  Se o nosso SYN foi reconhecido (talvez neste
     segmento de entrada) o nível de precedência do segmento de entrada
     corresponde exatamente ao nível de precedência local, se não redefinir
     deve ser enviado.

     Se o segmento de entrada tiver um campo ACK, a reconfiguração
     número de sequência do campo ACK do segmento, caso contrário, o
     reset tem número de seqüência zero e o campo ACK é definido como a soma
     do número de seqüência e comprimento do segmento do segmento de entrada.
     A conexão permanece no mesmo estado.

 [Página 36]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional

     3. Se a conexão estiver em um estado sincronizado (ESTABLISHED,
     FIN-WAIT-1, FIN-WAIT-2, FECHA-ESPERA, FECHAMENTO, ÚLTIMA RECEPÇÃO, TEMPO DE ESPERA),
     qualquer segmento inaceitável (fora do número de seqüência da janela ou
     número de confirmação inaceitável) deve provocar apenas uma
     segmento de confirmação contendo o número de sequência de envio atual
     e uma confirmação indicando o próximo número de sequência esperado
     para ser recebido, e a conexão permanece no mesmo estado.

     Se um segmento de entrada tiver um nível de segurança, compartimento ou
     precedência que não corresponde exatamente ao nível e compartimento,
     e precedência solicitada para a conexão, um reset é enviado e
     conexão vai para o estado CLOSED.  A redefinição leva sua sequência
     número do campo ACK do segmento de entrada.

   Redefinir Processamento

   Em todos os estados, exceto SYN-SENT, todos os segmentos de redefinição (RST) são validados
   verificando seus campos SEQ.  Um reset é válido se o seu número de sequência
   está na janela.  No estado SYN-SENT (um RST recebido em resposta
   para um SYN inicial), o RST é aceitável se o campo ACK
   reconhece o SYN.

   O receptor de um RST primeiro valida e muda de estado.  Se o
   receptor estava no estado LISTEN, ignora-o.  Se o receptor estava
   no estado SYN-RECEIVED e anteriormente estava no estado LISTEN,
   então o receptor retorna ao estado LISTEN, caso contrário o receptor
   aborta a conexão e vai para o estado CLOSED.  Se o receptor
   estava em qualquer outro estado, aborta a conexão e aconselha o usuário
   e vai para o estado CLOSED.

 3.5 .  Fechando uma conexão

   CLOSE é uma operação que significa "não tenho mais dados para enviar".  o
   noção de fechamento de uma conexão full-duplex está sujeita a ambígua
   interpretação, é claro, já que pode não ser óbvio como tratar
   o lado de recepção da conexão.  Nós escolhemos tratar o CLOSE
   de uma maneira simples.  O usuário que CLOSEs pode continuar a RECEBER
   até que ele seja informado de que o outro lado também está fechado.  Assim, um programa
   poderia iniciar vários SENDs seguidos de um CLOSE, e depois continuar
   RECEIVE até sinalizar que um RECEIVE falhou porque o outro lado
   FECHADO.  Assumimos que o TCP sinalizará um usuário, mesmo que não
   RECEIVE estão pendentes, que o outro lado fechou, então o usuário
   pode terminar seu lado graciosamente.  Um TCP entregará confiavelmente todos
   buffers enviados antes da conexão foi fechado para um usuário que não espera
   dados em troca só precisa esperar para ouvir a conexão foi fechada
   com sucesso para saber que todos os seus dados foram recebidos no destino
   TCP.  Os usuários devem continuar lendo as conexões que fecham para envio até
   o TCP diz que não há mais dados.

 [Página 37]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

   Existem basicamente três casos:

     1) O usuário inicia dizendo ao TCP para FECHAR a conexão

     2) O TCP remoto inicia enviando um sinal de controle FIN

     3) Ambos os usuários FECHAM simultaneamente

   Caso 1: usuário local inicia o fechamento

     Neste caso, um segmento FIN pode ser construído e colocado no
     fila de segmentos de saída.  Nenhum outro envio do usuário será
     aceita pelo TCP, e entra no estado FIN-WAIT-1.  RECEIVOS
     são permitidos neste estado.  Todos os segmentos que antecedem e incluem FIN
     será retransmitido até ser reconhecido.  Quando o outro TCP
     ambos reconheceram o FIN e enviaram um FIN do seu próprio, o primeiro TCP
     pode ACK esta FIN.  Note que um TCP recebendo um FIN irá ACK, mas não
     envie seu próprio FIN até que seu usuário tenha FECHADO a conexão também.

   Caso 2: TCP recebe um FIN da rede

     Se um FIN não solicitado chegar da rede, o TCP receptor
     pode ACK-lo e dizer ao usuário que a conexão está fechando.  o
     o usuário responderá com um CLOSE, sobre o qual o TCP pode enviar um FIN para
     o outro TCP depois de enviar os dados restantes.  O TCP aguarda
     até que o seu próprio FIN seja reconhecido, após o que elimina o
     conexão.  Se um ACK não for exibido, após o tempo limite do usuário
     a conexão é abortada e o usuário é informado.

   Caso 3: ambos os usuários fecham simultaneamente

     Um CLOSE simultâneo por usuários em ambas as extremidades de uma conexão faz com que
     Segmentos FIN a serem trocados.  Quando todos os segmentos que antecedem as FINs
     foram processados ​​e reconhecidos, cada TCP pode ACK o FIN
     recebeu.  Ambos irão, ao receber estes ACKs, apagar o
     conexão.

 [Página 38]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional


       TCP A TCP B

   1. ESTABELECIDO ESTABELECIDO

   2. (fechar)
       FIN-WAIT-1 -> <SEQ = 100> <ACK = 300> <CTL = FIN, ACK> -> FECHAR-ESPERAR

   3. FIN-WAIT-2 <- <SEQ = 300> <ACK = 101> <CTL = ACK> <- FECHAR-ESPERAR

   4. (fechar)
       TEMPO DE ESPERA <- <SEQ = 300> <ACK = 101> <CTL = FIN, ACK> <- LAST-ACK

   5. TEMPO DE ESPERA -> <SEQ = 101> <ACK = 301> <CTL = ACK> -> FECHADO

   6. (2 MSL)
       FECHADAS

                          Seqüência Close Normal

                                Figura 13

       TCP A TCP B

   1. ESTABELECIDO ESTABELECIDO

   2. (Fechar) (Fechar)
       FIN-WAIT-1 -> <SEQ = 100> <ACK = 300> <CTL = FIN, ACK> ... FIN-ESPERA-1
                   <- <SEQ = 300> <ACK = 100> <CTL = FIN, ACK> <-
                   ... <SEQ = 100> <ACK = 300> <CTL = FIN, ACK> ->

   3. FECHAMENTO -> <SEQ = 101> <ACK = 301> <CTL = ACK> ... ENCERRAMENTO
                   <- <SEQ = 301> <ACK = 101> <CTL = ACK> <-
                   ... <SEQ = 101> <ACK = 301> <CTL = ACK> ->

   4. TIME-WAIT TIME-WAIT
       (2 MSL) (2 MSL)
       FECHADO FECHADO

                       Sequência de Close Simultânea

                                Figura 14

 [Página 39]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

 3.6 .  Precedência e Segurança

   A intenção é que a conexão seja permitida apenas entre portas operando
   com exatamente os mesmos valores de segurança e compartimento e no
   maior do nível de precedência solicitado pelas duas portas.

   Os parâmetros de precedência e segurança usados ​​no TCP são exatamente
   definido no Internet Protocol (IP) [ 2 ].  Ao longo deste TCP
   especificação, o termo "segurança / compartimento" destina-se a indicar
   os parâmetros de segurança utilizados em IP, incluindo segurança, compartimento,
   grupo de usuários e restrições de manuseio.

   Uma tentativa de conexão com valores de segurança / compartimento incompatíveis ou
   menor valor de precedência deve ser rejeitado enviando um reset.  Rejeitando
   uma conexão devido a uma precedência muito baixa só ocorre após um
   o reconhecimento do SYN foi recebido.

   Note que os módulos TCP que operam apenas com o valor padrão de
   precedência ainda terá que verificar a precedência de entrada
   segmentos e, possivelmente, aumentar o nível de precedência que eles usam no
   conexão.

   Os parâmetros de segurança podem ser usados ​​mesmo em um ambiente não seguro
   (os valores indicariam dados não classificados), portanto hospeda
   ambientes não seguros devem estar preparados para receber a segurança
   parâmetros, embora eles não precisem enviá-los.

 3.7 .  Comunicação de dados

   Uma vez estabelecida a conexão, os dados são comunicados pelo
   troca de segmentos.  Porque segmentos podem ser perdidos devido a erros
   (falha no teste de soma de verificação) ou congestionamento de rede, o TCP usa
   retransmissão (após um tempo limite) para garantir a entrega de todos os segmentos.
   Segmentos duplicados podem chegar devido a rede ou retransmissão TCP.
   Como discutido na seção sobre números de seqüência, o TCP executa
   determinados testes nos números de sequência e confirmação no
   segmentos para verificar sua aceitabilidade.

   O remetente dos dados controla o próximo número de sequência a ser usado
   a variável SND.NXT.  O receptor de dados acompanha o próximo
   número de sequência esperado na variável RCV.NXT.  O remetente dos dados
   controla o número de sequência não reconhecido mais antigo no
   variável SND.UNA.  Se o fluxo de dados estiver momentaneamente ocioso e todos os dados
   enviado foi reconhecido, então as três variáveis ​​serão iguais.

   Quando o remetente cria um segmento e o transmite, o remetente avança
   SND.NXT.  Quando o receptor aceita um segmento, ele avança RCV.NXT e
   envia uma confirmação.  Quando o remetente de dados recebe um

 [Página 40]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional

   reconhecimento avança SND.UNA.  Até que ponto os valores de
   essas variáveis ​​diferem é uma medida do atraso na comunicação.
   A quantidade pela qual as variáveis ​​são avançadas é a duração do
   dados no segmento.  Note que, uma vez no estado ESTABLISHED, todos
   segmentos devem conter informações atuais de reconhecimento.

   A chamada do usuário CLOSE implica uma função push, assim como o controle FIN
   sinalizar em um segmento de entrada.

   Tempo limite de retransmissão

   Devido à variabilidade das redes que compõem um
   sistema de internetwork ea ampla gama de usos de conexões TCP
   O tempo limite de retransmissão deve ser determinado dinamicamente.  Um procedimento
   para determinar um tempo de retransmissão é dado aqui como um
   ilustração.

     Um exemplo de procedimento de tempo limite de retransmissão

       Meça o tempo decorrido entre o envio de um octeto de dados com um
       número de sequência particular e receber uma confirmação de que
       abrange esse número de sequência (os segmentos enviados não precisam corresponder
       segmentos recebidos).  Este tempo decorrido medido é o Round Trip
       Tempo (RTT).  Em seguida, calcule um Tempo de Ida e Volta Suavizado (SRTT) como:

         SRTT = (ALFA * SRTT) + ((1-ALFA) * RTT)

       e com base nisso, calcule o timeout de retransmissão (RTO) como:

         RTO = min [UBOUND, max [LBOUND, (BETA * SRTT)]]

       onde UBOUND é um limite superior no tempo limite (por exemplo, 1 minuto),
       LBOUND é um limite inferior no tempo limite (por exemplo, 1 segundo), ALPHA é
       um fator de suavização (por exemplo, .8 a .9) e BETA é uma variação de atraso
       fator (por exemplo, 1,3 a 2,0).

   A comunicação da informação urgente

   O objetivo do mecanismo urgente do TCP é permitir que o usuário remetente
   para estimular o usuário receptor a aceitar alguns dados urgentes e
   permitir que o TCP receptor indique ao usuário receptor quando todos
   os dados urgentes atualmente conhecidos foram recebidos pelo usuário.

   Esse mecanismo permite que um ponto no fluxo de dados seja designado como
   o fim da informação urgente.  Sempre que este ponto é antes da
   o número de seqüência de recepção (RCV.NXT) no TCP receptor, que o TCP
   deve dizer ao usuário para entrar em "modo urgente";  quando a sequência de recebimento
   número alcança o ponteiro urgente, o TCP deve informar ao usuário para ir

 [Página 41]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

   em "modo normal".  Se o ponteiro urgente for atualizado enquanto o usuário
   está em "modo urgente", a atualização será invisível para o usuário.

   O método emprega um campo urgente que é transportado em todos os segmentos
   transmitido.  O sinalizador de controle URG indica que o campo urgente é
   significativo e deve ser adicionado ao número de sequência do segmento para produzir
   o ponteiro urgente.  A ausência desta bandeira indica que existe
   Não há dados urgentes pendentes.

   Para enviar uma indicação urgente, o usuário também deve enviar pelo menos um
   octeto.  Se o usuário remetente também indicar um push, a entrega oportuna de
   as informações urgentes para o processo de destino são aprimoradas.

   Gerenciando a janela

   A janela enviada em cada segmento indica o intervalo de seqüência
   números o remetente da janela (o receptor de dados) está atualmente
   preparado para aceitar.  Há uma suposição de que isso está relacionado
   o espaço disponível no buffer de dados disponível para este
   conexão.

   Indicar uma janela grande incentiva as transmissões.  Se mais dados
   chega do que pode ser aceite, será descartado.  Isso resultará
   em retransmissões excessivas, adicionando desnecessariamente à carga no
   rede e os TCPs.  Indicar uma pequena janela pode restringir
   transmissão de dados a ponto de introduzir um atraso de ida e volta
   entre cada novo segmento transmitido.

   Os mecanismos fornecidos permitem que um TCP anuncie uma grande janela e
   subsequentemente anunciar uma janela muito menor sem ter aceitado
   muitos dados.  Isso, chamado de "encolhendo a janela", é fortemente
   desanimado.  O princípio da robustez determina que os TCPs não
   encolher a janela eles mesmos, mas estará preparado para tal comportamento
   por parte de outros TCPs.

   O TCP remetente deve estar preparado para aceitar do usuário e enviar
   menos um octeto de novos dados, mesmo que a janela de envio seja zero.  o
   O envio de TCP deve retransmitir regularmente para o TCP receptor mesmo quando
   a janela é zero.  Dois minutos são recomendados para a retransmissão
   intervalo quando a janela é zero.  Esta retransmissão é essencial para
   garantir que quando o TCP tem uma janela zero a reabertura do
   janela será relatada de forma confiável para o outro.

   Quando o TCP receptor recebe uma janela zero e um segmento chega, deve
   ainda enviar uma confirmação mostrando seu próximo número de seqüência esperado
   e janela atual (zero).

   O TCP remetente empacota os dados a serem transmitidos em segmentos

 [Página 42]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional

   que se ajustam à janela atual e podem reembalar segmentos no
   fila de retransmissão.  Esse reempacotamento não é necessário, mas pode ser
   útil.

   Em conexão com um fluxo de dados unidirecional, as informações da janela
   ser transportado em segmentos de reconhecimento que todos têm a mesma sequência
   número de modo que não haverá maneira de reordená-los se eles saem de
   ordem.  Este não é um problema sério, mas permitirá a janela
   informações para ser de vez em quando temporariamente com base em relatórios antigos de
   o receptor de dados.  Um refinamento para evitar esse problema é agir
   as informações da janela de segmentos que carregam o mais alto
   número de confirmação (ou seja, segmentos com número de confirmação
   igual ou maior que o maior recebido anteriormente).

   O procedimento de gerenciamento de janelas tem influência significativa na
   desempenho de comunicação.  Os comentários a seguir são sugestões para
   implementadores.

     Sugestões de Gerenciamento de Janelas

       Alocar uma janela muito pequena faz com que os dados sejam transmitidos
       muitos pequenos segmentos quando melhor desempenho é alcançado usando
       menos segmentos grandes.

       Uma sugestão para evitar pequenas janelas é que o receptor
       adiar a atualização de uma janela até que a alocação adicional esteja em
       pelo menos X por cento da alocação máxima possível para o
       conexão (onde X pode ser de 20 a 40).

       Outra sugestão é que o remetente evite enviar pequenos
       segmentos, esperando até que a janela é grande o suficiente antes
       enviando dados.  Se o usuário sinalizar uma função push, o
       os dados devem ser enviados mesmo que seja um segmento pequeno.

       Note que os agradecimentos não devem ser atrasados ​​ou desnecessários
       retransmissões resultarão.  Uma estratégia seria enviar um
       reconhecimento quando chega um pequeno segmento (sem atualizar o
       informações da janela) e, em seguida, enviar outro aviso com
       novas informações da janela quando a janela é maior.

       O segmento enviado para sondar uma janela zero também pode começar um desmembramento
       de dados transmitidos em segmentos menores e menores.  Se um
       segmento contendo um único octeto de dados enviado para sondar uma janela zero
       é aceito, consome um octeto da janela agora disponível.
       Se o TCP remetente simplesmente enviar o máximo que puder, sempre que
       janela é diferente de zero, os dados transmitidos serão divididos em
       alternando segmentos grandes e pequenos.  Conforme o tempo passa, ocasional
       pausas no receptor fazendo alocação de janela disponível

 [Página 43]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

       resultar em quebrar os grandes segmentos em um pequeno e não tão
       par grande.  E depois de um tempo a transmissão de dados será em
       principalmente pequenos segmentos.

       A sugestão aqui é que as implementações do TCP precisam
       tente ativamente combinar pequenas alocações de janelas em
       janelas, já que os mecanismos de gerenciamento da janela tendem a
       para muitas pequenas janelas nas implementações mais simples.

 3.8 .  Interfaces

   Existem duas interfaces de interesse: a interface usuário / TCP
   e a interface TCP / nível inferior.  Nós temos um modelo bastante elaborado
   do usuário / interface TCP, mas a interface para o nível inferior
   módulo de protocolo não é especificado aqui, pois será especificado
   em detalhe pela especificação do protocolo de nível lowel.  Para o
   caso em que o nível mais baixo é IP, notamos alguns dos valores dos parâmetros
   que os TCPs podem usar.

   Interface Usuário / TCP

     A seguinte descrição funcional dos comandos do usuário para o TCP é,
     na melhor das hipóteses, ficcional, uma vez que cada sistema operacional terá diferentes
     instalações.  Consequentemente, devemos alertar os leitores que diferentes TCP
     implementações podem ter diferentes interfaces de usuário.  No entanto, todos
     Os TCPs devem fornecer um conjunto mínimo de serviços para garantir
     que todas as implementações TCP podem suportar o mesmo protocolo
     hierarquia.  Esta seção especifica as interfaces funcionais
     exigido de todas as implementações do TCP.

     Comandos do usuário TCP

       As seções a seguir caracterizam funcionalmente um USER / TCP
       interface.  A notação usada é semelhante à maioria dos procedimentos ou
       chamadas de função em linguagens de alto nível, mas esse uso não é
       para descartar chamadas de serviço de tipo de interceptação (por exemplo, SVCs, UUOs,
       EMTs).

       Os comandos do usuário descritos abaixo especificam as funções básicas
       O TCP deve executar para suportar a comunicação entre processos.
       Implementações individuais devem definir seu próprio formato exato, e
       podem fornecer combinações ou subconjuntos das funções básicas
       chamadas individuais.  Em particular, algumas implementações podem desejar
       automaticamente ABRIR uma conexão no primeiro SEND ou RECEBER
       emitido pelo usuário para uma determinada conexão.

 [Página 44]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional

       Ao fornecer recursos de comunicação entre processos, o TCP deve
       não só aceita comandos, mas também deve retornar informações para o
       processos que serve.  Este último consiste em:

         (a) informações gerais sobre uma conexão (por exemplo, interrupções,
         fechamento remoto, ligação de soquete estrangeiro não especificado).

         (b) respostas a comandos específicos do usuário indicando sucesso ou
         vários tipos de falhas.

       Aberto

         Formato: OPEN (porta local, socket externo, ativo / passivo
         [, tempo limite] [, precedência] [, segurança / compartimento] [, opções])
         -> nome da conexão local

         Nós assumimos que o TCP local está ciente da identidade do
         processos que serve e irá verificar a autoridade do processo
         para usar a conexão especificada.  Dependendo do
         implementação do TCP, a rede local e os identificadores TCP
         para o endereço de origem será fornecido pelo TCP ou pelo
         protocolo de nível inferior (por exemplo, IP).  Essas considerações são
         resultado da preocupação com a segurança, na medida em que não
         capaz de se mascarar como outro, e assim por diante.  Da mesma forma, não
         processo pode mascarar como outro sem o conluio do
         TCP.

         Se o sinalizador ativo / passivo estiver definido como passivo, então este é um
         ligue para LISTEN para uma conexão de entrada.  Um aberto passivo pode
         ter um soquete estrangeiro totalmente especificado para esperar por um
         conexão particular ou uma tomada estrangeira não especificada para esperar
         para qualquer chamada.  Uma chamada passiva totalmente especificada pode ser ativada
         pela subsequente execução de um SEND.

         Um bloco de controle de transmissão (TCB) é criado e parcialmente
         preenchido com dados dos parâmetros do comando OPEN.

         Em um comando OPEN ativo, o TCP iniciará o procedimento para
         sincronizar (ou seja, estabelecer) a conexão de uma só vez.

         O tempo limite, se presente, permite que o chamador configure um tempo limite
         para todos os dados submetidos ao TCP.  Se os dados não forem bem-sucedidos
         entregue no destino dentro do período de tempo limite, o TCP
         abortará a conexão.  O presente padrão global é de cinco
         minutos.

         O TCP ou algum componente do sistema operacional verificará
         a autoridade dos usuários para abrir uma conexão com o

 [Página 45]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

         precedência ou segurança / compartimento.  A ausência de precedência
         ou especificação de segurança / compartimento na chamada OPEN
         os valores padrão devem ser usados.

         O TCP aceitará solicitações recebidas como correspondência apenas se o
         informações de segurança / compartimento são exatamente as mesmas e somente se
         a precedência é igual ou superior à precedência
         solicitado na chamada ABERTA.

         A precedência para a conexão é o maior dos valores
         solicitado na chamada OPEN e recebido da entrada
         pedido, e fixado a esse valor para a vida do
         conexão. Os implementadores podem querer dar ao usuário o controle de
         esta negociação de precedência.  Por exemplo, o usuário pode estar
         permissão para especificar que a precedência deve ser exatamente igualada,
         ou que qualquer tentativa de aumentar a precedência seja confirmada pelo
         do utilizador.

         Um nome de conexão local será retornado ao usuário pelo TCP.
         O nome da conexão local pode ser usado como um termo de mão curta
         para a conexão definida pelo <socket local, socket estrangeiro>
         par.

       Enviar

         Formato: SEND (nome da conexão local, endereço do buffer, byte
         count, PUSH flag, URGENT flag [, timeout])

         Esta chamada faz com que os dados contidos no buffer de usuário indicado
         para ser enviado na conexão indicada.  Se a conexão tiver
         não foi aberto, o envio é considerado um erro.  Alguns
         implementações podem permitir que os usuários ENVIEM primeiro;  nesse caso, um
         ABERTO automático seria feito.  Se o processo de chamada não for
         autorizado a usar esta conexão, um erro é retornado.

         Se o sinalizador PUSH estiver definido, os dados devem ser transmitidos imediatamente
         para o receptor, eo bit PUSH será definido no último TCP
         segmento criado a partir do buffer. Se o sinalizador PUSH não estiver definido,
        os dados podem ser combinados com dados de subseqüentes SENDs para
        eficiência de transmissão.

        Se o sinalizador URGENT estiver definido, os segmentos enviados para o TCP de destino
        terá o ponteiro urgente definido. O TCP receptor irá sinalizar
        a condição urgente para o processo de recepção se o urgente
        ponteiro indica que os dados que precedem o ponteiro urgente não
        consumido pelo processo de recebimento. O propósito de urgente
        é estimular o receptor para processar os dados urgentes e para
        indicar ao receptor quando todas as informações urgentes

[Página 46]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional

        dados foram recebidos. O número de vezes que o usuário de envio
        Sinais TCP urgentes não serão necessariamente iguais ao número
        de vezes que o usuário receptor será notificado da presença de
        dados urgentes.

        Se nenhum soquete estrangeiro foi especificado no OPEN, mas o
        conexão é estabelecida (por exemplo, porque uma conexão LISTENing
        tornou-se específico devido a um segmento estrangeiro que chega para o
        socket local), então o buffer designado é enviado para o
         tomada estrangeira. Usuários que fazem uso do OPEN com um não especificado
        tomada estrangeira pode fazer uso de enviar sem nunca explicitamente
        sabendo o endereço do soquete estrangeiro.

        No entanto, se um SEND for tentado antes do soquete estrangeiro
        se torna especificado, um erro será retornado. Os usuários podem usar o
        STATUS chamada para determinar o status da conexão. Em alguns
        implementações o TCP pode notificar o usuário quando um não especificado
        soquete está ligado.

        Se um tempo limite for especificado, o tempo limite atual do usuário para esse
        a conexão é alterada para a nova.

        Na implementação mais simples, SEND não retornaria o controle para
        o processo de envio até que a transmissão esteja completa
        ou o tempo limite foi excedido. No entanto, este método simples
        está sujeito a deadlocks (por exemplo, ambos os lados do
        conexão pode tentar fazer SENDs antes de fazer qualquer RECEIVE) e
        oferece desempenho ruim, por isso não é recomendado. Mais
        implementação sofisticada retornaria imediatamente para permitir
        o processo a ser executado simultaneamente com a E / S da rede e,
        além disso, para permitir que vários SENDs estejam em andamento.
        Múltiplos SENDs são servidos na ordem de chegada, primeiro a ser servido
        o TCP enfileirará aqueles que não podem atender imediatamente.

        Assumimos implicitamente uma interface de usuário assíncrona
        que um envio depois elicia algum tipo de sinal ou
        pseudo-interrupção do TCP de serviço. Uma alternativa é
        retornar uma resposta imediatamente. Por exemplo, os SENDs podem retornar
        confirmação local imediata, mesmo que o segmento enviado não tenha
        foi reconhecido pelo TCP distante. Nós poderíamos ser otimistas
        assumir o sucesso final. Se estivermos errados, a conexão será
        fechar de qualquer maneira devido ao tempo limite. Em implementações deste
        tipo (síncrono), ainda haverá algum assíncrono
        sinais, mas estes vão lidar com a conexão em si, e não
        com segmentos ou buffers específicos.

        Para que o processo possa distinguir entre erro ou sucesso
        indicações para diferentes SENDs, pode ser apropriado para o

 [Página 47]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

        endereço do buffer a ser retornado junto com a resposta codificada para
        o pedido SEND. Sinais TCP para usuário são discutidos abaixo,
        indicando as informações que devem ser devolvidas ao
        processo de chamada.

       Receber

        Formato: RECEIVE (nome da conexão local, endereço do buffer, byte
        contar) -> contagem de bytes, bandeira urgente, empurre a bandeira

        Esse comando aloca um buffer de recebimento associado ao
        conexão especificada. Se nenhum OPEN precede este comando ou o
        processo de chamada não está autorizado a usar esta conexão, um
        erro é retornado.

        Na implementação mais simples, o controle não retornaria ao
        programa de chamada até que o buffer seja preenchido ou
        erro ocorreu, mas este esquema está altamente sujeito a deadlocks.
        Uma implementação mais sofisticada permitiria vários
        RECEBÍVEIS estarem pendentes de uma só vez. Estes seriam preenchidos como
        segmentos chegam. Esta estratégia permite aumentar o rendimento
        o custo de um esquema mais elaborado (possivelmente assíncrono) para
        notificar o programa de chamada que um PUSH foi visto ou um buffer
        preenchidas.

        Se dados suficientes chegarem para preencher o buffer antes que um PUSH seja visto,
        o sinalizador PUSH não será definido na resposta ao RECEIVE.
        O buffer será preenchido com o máximo de dados possível.  E se
        um PUSH é visto antes do buffer é preenchido o buffer será
        retornou parcialmente preenchido e PUSH indicado.

        Se houver dados urgentes, o usuário será informado assim que
        como chegou através de um sinal TCP-to-user. O usuário receptor
        deve, portanto, estar em "modo de urgência". Se o sinalizador URGENT estiver ativado,
        dados urgentes adicionais permanecem. Se o sinalizador URGENT estiver desativado,
        A chamada para RECEIVE retornou todos os dados urgentes e o usuário
        pode agora sair do "modo urgente". Observe que os dados após o
        ponteiro urgente (dados não urgentes) não pode ser entregue ao usuário
        no mesmo buffer com dados urgentes anteriores, a menos que
        limite é claramente marcado para o usuário.

        Para distinguir entre vários RECEIVAS pendentes e para
        cuidado com o caso de um buffer não estar completamente preenchido, o
        código de retorno é acompanhado por um ponteiro de buffer e um byte
        contagem indicando o tamanho real dos dados recebidos.

        Implementações alternativas de RECEIVE podem ter o TCP

[Página 48]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional

        alocar armazenamento de buffer, ou o TCP pode compartilhar um buffer de anel
        com o usuário.

       Fechar

        Formato: CLOSE (nome da conexão local)

        Este comando faz com que a conexão especificada seja fechada.  E se
        a conexão não está aberta ou o processo de chamada não é
        autorizado a usar esta conexão, um erro é retornado.
        Conexões de fechamento destina-se a ser uma operação graciosa em
        a sensação de que pendentes SENDs serão transmitidos (e
        retransmitido), como o controle de fluxo permite, até que todos tenham sido
        atendido. Assim, deve ser aceitável fazer vários SEND
        chamadas, seguido por um CLOSE, e esperar que todos os dados sejam enviados
        para o destino. Também deve ficar claro que os usuários devem
        continue a RECEBER nas conexões de FECHO, pois o outro lado
        pode estar tentando transmitir o último dos seus dados. Assim, FECHAR
        significa "não tenho mais para enviar", mas não significa "eu não vou
        receber mais. "Isso pode acontecer (se o protocolo de nível de
        não bem pensado) que o lado de fechamento é incapaz de se livrar
        de todos os seus dados antes de expirar. Neste evento, o CLOSE gira
        em ABORT, e o TCP de fechamento desiste.

        O usuário pode FECHAR a conexão a qualquer momento por conta própria
        iniciativa, ou em resposta a vários prompts do TCP
        (por exemplo, fechamento remoto executado, tempo limite de transmissão excedido,
        destino inacessível).

        Porque fechar uma conexão requer comunicação com o
        TCP externo, as conexões podem permanecer no estado de fechamento
        tempo curto. Tenta reabrir a conexão antes do TCP
        respostas para o comando CLOSE resultarão em respostas de erro.

        Fechar também implica em função push.

       Status

        Formato: STATUS (nome da conexão local) -> dados de status

        Este é um comando do usuário dependente da implementação e pode ser
        excluídos sem efeito adverso. A informação retornada seria
        normalmente vêm do TCB associado à conexão.

        Este comando retorna um bloco de dados contendo o seguinte
        em formação:

          tomada local,

 [Página 49]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

          tomada estrangeira,
          nome da conexão local,
          receber janela,
          enviar janela,
          estado de conexão,
          número de buffers aguardando confirmação,
          número de buffers pendentes de recebimento,
          estado urgente,
          precedência,
          segurança / compartimento,
          e tempo limite de transmissão.

        Dependendo do estado da conexão ou da
        implementação, algumas dessas informações podem não ser
        disponível ou significativo. Se o processo de chamada não for
        autorizado a usar esta conexão, um erro é retornado.  este
        impede que processos não autorizados obtenham informações sobre um
         conexão.

      Abortar

        Formato: ABORT (nome da conexão local)

        Este comando faz com que todos os SENDs e RECEIVES pendentes sejam
        abortada, o TCB a ser removido e uma mensagem especial RESET para
        ser enviado para o TCP no outro lado da conexão.
        Dependendo da implementação, os usuários podem receber abortar
        indicações para cada pendente ENVIAR ou RECEBER, ou pode simplesmente
        receber um aviso de ABORT.

    Mensagens de TCP para usuário

      Assume-se que o ambiente do sistema operacional fornece um
      meios para o TCP assíncrona sinalizar o programa do usuário.  Quando
      o TCP sinaliza um programa do usuário, certas informações são passadas
       para o usuário. Muitas vezes, na especificação, a informação será
      uma mensagem de erro. Em outros casos haverá informação
      relativas à conclusão do processamento de um envio ou receber ou
      outra chamada de usuário.

      As seguintes informações são fornecidas:

        Nome da conexão local sempre
        String de Resposta Sempre
        Endereço de Buffer Enviar e Receber
        Contagem de bytes (conta bytes recebidos) Receber
        Empurre bandeira Receba
        Sinalizador urgente Receber
[Página 50]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional

  Interface TCP / Nível Inferior

    O TCP chama um módulo de protocolo de nível inferior para enviar e
    receber informações através de uma rede. Um caso é o da ARPA
    sistema de internetwork, onde o módulo de nível inferior é a Internet
    Protocolo (IP) [ 2 ].

    Se o protocolo de nível inferior é IP, ele fornece argumentos para um tipo
    de serviço e por um tempo para viver. TCP usa as seguintes configurações
    para estes parâmetros:

      Tipo de Serviço = Precedência: rotina, Atraso: normal, Taxa de transferência:
      normal, Confiabilidade: normal; ou 00000000.

      Tempo de vida = um minuto ou 00111100.

        Observe que a vida útil máxima do segmento é de dois minutos.
        Aqui nós explicitamente pedimos que um segmento seja destruído se não puder
        ser entregue pelo sistema de internet dentro de um minuto.

    Se o nível mais baixo for IP (ou outro protocolo que forneça
    recurso) e roteamento de origem é usado, a interface deve permitir
    encaminhar informações a serem comunicadas. Isso é especialmente importante
    para que os endereços de origem e destino usados ​​no TCP
    checksum seja a origem e destino final.  Isto é
    também é importante preservar a rota de retorno para atender a conexão
    solicitações de.

    Qualquer protocolo de nível inferior terá que fornecer o endereço de origem,
    endereço de destino, campos de protocolo e alguma maneira de determinar
    o "comprimento TCP", ambos para fornecer o serviço funcional equivalente
    IP e para ser usado na soma de verificação TCP.

 [Página 51]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional

 3.9 . Processamento de Eventos

  O processamento descrito nesta seção é um exemplo de uma possível
   implementação. Outras implementações podem ter um pouco diferente
  seqüências de processamento, mas elas devem diferir daquelas
  seção apenas em detalhes, não em substância.

  A atividade do TCP pode ser caracterizada como respondendo a eventos.
  Os eventos que ocorrem podem ser agrupados em três categorias: chamadas do usuário,
  segmentos de chegada e tempos limite. Esta seção descreve o
  processamento do TCP faz em resposta a cada um dos eventos.  Em muitos
  Em alguns casos, o processamento necessário depende do estado da conexão.

    Eventos que ocorrem:

      Chamadas do usuário

         ABERTO
         ENVIAR
         RECEBER
         FECHAR
        ABORTAR
         STATUS

      Chegando Segmentos

        SEGMENTO CHEGA

       Tempos limite

        TIMEOUT DO USUÁRIO
        TIMEOUT DE RETRANSMISSÃO
        TIME-WAIT TIMEOUT

  O modelo da interface TCP / usuário é que os comandos do usuário recebem
  retorno imediato e, possivelmente, uma resposta atrasada através de um evento ou
  pseudo interrupção. Nas seguintes descrições, o termo "sinal"
  significa causar uma resposta atrasada.

  As respostas de erro são dadas como cadeias de caracteres. Por exemplo, usuário
  comandos referenciando conexões que não existem recebem "erro:
  conexão não aberta ".

  Por favor, observe no seguinte que toda aritmética em números de seqüência,
  números de confirmação, windows, et cetera, é módulo 2 ** 32 o tamanho
  do espaço numérico de seqüência. Observe também que "= <" significa menor que ou
  igual a (módulo 2 ** 32).

[Página 52]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional

  Uma maneira natural de pensar sobre o processamento de segmentos de entrada é
  imagine que eles são testados pela primeira vez para o número de seqüência adequado (ou seja,
  que seu conteúdo está no intervalo da "janela de recebimento" esperada
  no espaço numérico de seqüência) e, em seguida, eles são geralmente enfileirados
  e processado em ordem numérica de seqüência.

  Quando um segmento se sobrepõe a outros segmentos já recebidos, nós reconstruímos
  o segmento para conter apenas os novos dados e ajustar os campos de cabeçalho
  ser consistente.

  Observe que, se nenhuma alteração de estado for mencionada, o TCP permanecerá no mesmo
   Estado.


 [Página 53]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional
                                                               Chamada aberta

  Chamada aberta

    ESTADO FECHADO (isto é, o TCB não existe)

      Crie um novo bloco de controle de transmissão (TCB) para manter a conexão
      informação de estado. Preencha o identificador de soquete local, estrangeiro
      soquete, precedência, segurança / compartimento e tempo limite do usuário
       em formação. Note que algumas partes da tomada externa podem ser
      não especificado em um OPEN passivo e devem ser preenchidos pelo
      parâmetros do segmento SYN de entrada. Verifique a segurança e
      precedência solicitada são permitidas para este usuário, se não retornar
      "erro: precedência não permitida" ou "erro: segurança / compartimento
      não permitido. "Se passivo, digite o estado LISTEN e retorne.
      ativo e o soquete externo não é especificado, retorna "erro:
      soquete não especificado "; se ativo e o soquete estrangeiro
      especificado, emita um segmento SYN. Um número inicial de sequência de envio
      (ISS) é selecionado. Um segmento SYN da forma <SEQ = ISS> <CTL = SYN>
      é enviado. Ajuste SND.UNA para ISS, SND.NXT para ISS + 1, insira SYN-SENT
      estado e retorno.

      Se o chamador não tiver acesso ao soquete local especificado,
      return "erro: conexão ilegal para este processo".  Se houver
      não há espaço para criar uma nova conexão, retornar "erro: insuficiente
      Recursos".

    ESCUTE ESTADO

      Se ativo e o soquete externo for especificado, altere o
      conexão de passivo para ativo, selecione um ISS. Envie um SYN
      segmento, defina SND.UNA para ISS, SND.NXT para ISS + 1. Digite SYN-SENT
       Estado. Os dados associados a SEND podem ser enviados com o segmento SYN ou
      na fila para transmissão depois de entrar no estado ESTABELECIDO.  o
      bit urgente se solicitado no comando deve ser enviado com os dados
      segmentos enviados como resultado desse comando. Se não houver espaço para
      enfileirar a solicitação, responda com "erro: recursos insuficientes".
      Se o soquete externo não foi especificado, retorne "error: foreign
      soquete não especificado ".

[Página 54]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional
Chamada aberta


    SYN-SENT STATE
    ESTADO RECEBIDO
    ESTADO ESTABELECIDO
    FIN-WAIT-1 STATE
    FIN-WAIT-2 STATE
    ESTADO DE CLOSE-WAIT
    ESTADO DE FECHAMENTO
    ESTADO LAST-ACK
    ESTADO TIME-WAIT

      Retornar "erro: conexão já existe".

 [Página 55]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional
                                                               ENVIAR Chamada

  ENVIAR Chamada

    ESTADO FECHADO (isto é, o TCB não existe)

      Se o usuário não tiver acesso a essa conexão, retorne
      "erro: conexão ilegal para este processo".

      Caso contrário, retorne "error: connection does not exist".

    ESCUTE ESTADO

      Se o soquete externo for especificado, altere a conexão
      de passivo para ativo, selecione um ISS. Envie um segmento SYN, defina
      SND.UNA para ISS, SND.NXT para ISS + 1. Digite o estado SYN-SENT. Dados
      associados a SEND podem ser enviados com segmento SYN ou enfileirados
      transmissão após entrar no estado ESTABELECIDO. O bit urgente se
      solicitado no comando deve ser enviado com os segmentos de dados enviados
      como resultado desse comando. Se não houver espaço para enfileirar
      pedido, responda com "erro: recursos insuficientes".  E se
      Soquete estrangeiro não foi especificado e, em seguida, retornar "error: foreign
      soquete não especificado ".

    SYN-SENT STATE
    ESTADO RECEBIDO

      Filtre os dados para transmissão depois de entrar no estado ESTABLISHED.
      Se não há espaço para fila, responda com "erro: insuficiente
      Recursos".

    ESTADO ESTABELECIDO
    ESTADO DE CLOSE-WAIT

      Segmentar o buffer e enviá-lo com um piggyback
      confirmação (valor de confirmação = RCV.NXT).  Se houver
      espaço insuficiente para lembrar esse buffer, simplesmente retorne "error:
      recursos insuficientes".

      Se o sinalizador urgente estiver definido, então SND.UP <- SND.NXT-1 e
      ponteiro urgente nos segmentos de saída.

[Página 56]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional
ENVIAR Chamada

    FIN-WAIT-1 STATE
    FIN-WAIT-2 STATE
    ESTADO DE FECHAMENTO
    ESTADO LAST-ACK
    ESTADO TIME-WAIT

      Retornar "erro: fechamento da conexão" e não solicita solicitação de serviço.

 [Página 57]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional
                                                            RECEBER Chamada

  RECEBER Chamada

    ESTADO FECHADO (isto é, o TCB não existe)

      Se o usuário não tiver acesso a essa conexão, retorne
      "erro: conexão ilegal para este processo".

      Caso contrário, retorne "error: connection does not exist".

    ESCUTE ESTADO
    SYN-SENT STATE
    ESTADO RECEBIDO

      Fila para processamento após entrar no estado ESTABLISHED. Se lá
      não há espaço para enfileirar essa solicitação, responda com "erro:
      recursos insuficientes".

    ESTADO ESTABELECIDO
    FIN-WAIT-1 STATE
    FIN-WAIT-2 STATE

      Se segmentos de entrada insuficientes forem enfileirados para satisfazer
      pedido, enfileirar o pedido. Se não houver espaço de fila para
      lembre-se do RECEBER, responda com "erro: insuficiente
      Recursos".

      Remontar os segmentos de entrada enfileirados no buffer de recebimento e retornar
      ao usuário. Marque "push seen" (PUSH) se este for o caso.

      Se o RCV.UP for antecipado aos dados atualmente sendo passados ​​para o
      usuário notificar o usuário da presença de dados urgentes.

      Quando o TCP assume a responsabilidade de entregar dados ao usuário
      esse fato deve ser comunicado ao remetente por meio de um
      reconhecimento. A formação de tal reconhecimento é
      descrito abaixo na discussão do processamento de uma entrada
       segmento.
[Página 58]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional
RECEBER Chamada

    ESTADO DE CLOSE-WAIT

      Como o lado remoto já enviou FIN, os RECEIVE devem ser
      satisfeito com o texto já disponível, mas ainda não entregue ao
      do utilizador. Se nenhum texto estiver aguardando a entrega, o RECEIVE receberá
      "error: connection closing" response. Caso contrário, qualquer restante
      o texto pode ser usado para satisfazer o RECEBIMENTO.

    ESTADO DE FECHAMENTO
    ESTADO LAST-ACK
    ESTADO TIME-WAIT

      Retornar "erro: fechamento da conexão".

 [Página 59]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional
                                                              FECHAR Chamada

  FECHAR Chamada

    ESTADO FECHADO (isto é, o TCB não existe)

      Se o usuário não tiver acesso a essa conexão, retorne
      "erro: conexão ilegal para este processo".

      Caso contrário, retorne "error: connection does not exist".

    ESCUTE ESTADO

      Quaisquer RECEIVEs pendentes são retornados com "erro: fechamento"
       respostas. Apague o TCB, insira o estado FECHADO e retorne.

    SYN-SENT STATE

      Exclua o TCB e retorne as respostas "error: closing" para qualquer
      ENVIOS em fila ou RECEBIMENTOS.

    ESTADO RECEBIDO

      Se nenhum envio tiver sido emitido e não houver dados pendentes para enviar,
      em seguida, formar um segmento FIN e enviá-lo e entrar no estado FIN-WAIT-1;
      caso contrário, a fila para processamento depois de entrar no estado ESTABLISHED.

    ESTADO ESTABELECIDO

      Coloque em fila até que todos os SENDs precedentes tenham sido segmentados,
      formar um segmento FIN e enviá-lo. Em qualquer caso, insira FIN-WAIT-1
       Estado.

    FIN-WAIT-1 STATE
    FIN-WAIT-2 STATE

      Estritamente falando, isso é um erro e deve receber um "erro:
      resposta de fechamento de conexão. Uma resposta "ok" seria
      aceitável, desde que uma segunda FIN não seja emitida (a primeira
      FIN pode ser retransmitido embora).

[Página 60]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional
FECHAR Chamada

    ESTADO DE CLOSE-WAIT

      Enfileire essa solicitação até que todos os SENDs anteriores tenham sido
      segmentado; em seguida, envie um segmento FIN, entre no estado CLOSING.

    ESTADO DE FECHAMENTO
    ESTADO LAST-ACK
    ESTADO TIME-WAIT

      Responda com "erro: fechamento da conexão".

 [Página 61]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional
                                                              Chamada ABORT

  Chamada ABORT

    ESTADO FECHADO (isto é, o TCB não existe)

      Se o usuário não tiver acesso a essa conexão, retorne
      "erro: conexão ilegal para este processo".

      Caso contrário, retorne "error: connection does not exist".

    ESCUTE ESTADO

      Quaisquer RECEIVOS pendentes devem ser devolvidos com "erro:
      conexão reset "respostas. Excluir TCB, digite estado FECHADO, e
       Retorna.

    SYN-SENT STATE

      Todos os ENVIOS e RECEBIDOS enfileirados devem receber "redefinição de conexão"
      notificação, exclua o TCB, insira o estado FECHADO e retorne.

    ESTADO RECEBIDO
    ESTADO ESTABELECIDO
    FIN-WAIT-1 STATE
    FIN-WAIT-2 STATE
    ESTADO DE CLOSE-WAIT

      Envie um segmento de redefinição:

        <SEQ = SND.NXT> <CTL = RST>

      Todos os ENVIOS e RECEBIDOS enfileirados devem receber "redefinição de conexão"
      notificação; todos os segmentos enfileirados para transmissão (exceto
      RST formado acima) ou retransmissão deve ser liberado, exclua o
      TCB, insira o estado FECHADO e retorne.

    ESTADO DE FECHAMENTO
    ESTADO LAST-ACK
    ESTADO TIME-WAIT

      Responda com "ok" e exclua o TCB, insira o estado FECHADO e
       Retorna.

[Página 62]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional
STATUS Call

  STATUS Call

    ESTADO FECHADO (isto é, o TCB não existe)

      Se o usuário não tiver acesso a essa conexão, retorne
      "erro: conexão ilegal para este processo".

      Caso contrário, retorne "error: connection does not exist".

    ESCUTE ESTADO

      Retornar "estado = LISTEN" e o ponteiro TCB.

    SYN-SENT STATE

      Retornar "estado = SYN-SENT" e o ponteiro TCB.

    ESTADO RECEBIDO

      Retornar "estado = SYN RECEBIDO" e o ponteiro TCB.

    ESTADO ESTABELECIDO

      Retornar "estado = ESTABLISHED" e o ponteiro TCB.

    FIN-WAIT-1 STATE

      Retornar "estado = FIN-WAIT-1" e o ponteiro TCB.

    FIN-WAIT-2 STATE

      Retornar "estado = FIN-WAIT-2" e o ponteiro TCB.

    ESTADO DE CLOSE-WAIT

      Retornar "state = CLOSE-WAIT" e o ponteiro TCB.

    ESTADO DE FECHAMENTO

      Retornar "state = CLOSING" e o ponteiro TCB.

    ESTADO LAST-ACK

      Retornar "state = LAST-ACK" e o ponteiro TCB.

 [Pg 63]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional
                                                             STATUS Call

    ESTADO TIME-WAIT

      Retornar "state = TIME-WAIT" e o ponteiro TCB.

[Página 64]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional
SEGMENTO CHEGA
  SEGMENTO CHEGA

    Se o estado for CLOSED (ou seja, o TCB não existir), então

      todos os dados no segmento de entrada são descartados. Uma entrada
      segmento contendo um RST é descartado. Um segmento de entrada não
      contendo um RST faz com que um RST seja enviado em resposta.  o
      valores de campo de confirmação e sequência são selecionados para tornar
      redefinir seqüência aceitável para o TCP que enviou a ofensa
       segmento.

      Se o bit ACK estiver desligado, o número de seqüência zero é usado,

        <SEQ = 0> <ACK = SEG.SEQ + SEG.LEN> <CTL = RST, ACK>

      Se o bit ACK estiver ligado,

        <SEQ = SEG.ACK> <CTL = RST>

       Retorna.

    Se o estado é LISTEN, então

      primeira verificação de um RST

        Um RST de entrada deve ser ignorado.  Retorna.

      segunda verificação para um ACK

        Qualquer confirmação é ruim se chegar em uma conexão ainda em
        o estado LISTEN. Um segmento de reposição aceitável deve ser formado
        para qualquer segmento de rolamento ACK que esteja chegando. O RST deve ser
        formatado da seguinte forma:

          <SEQ = SEG.ACK> <CTL = RST>

         Retorna.

      terceira verificação para um SYN

        Se o bit SYN estiver definido, verifique a segurança.  Se o
        segurança / compartimento no segmento de entrada não exatamente
        coincidir com a segurança / compartimento no TCB, em seguida, enviar um reset e
         Retorna.

          <SEQ = SEG.ACK> <CTL = RST>

 [Página 65]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional
                                                         SEGMENTO CHEGA

        Se o SEG.PRC for maior que o TCB.PRC, se permitido por
        o usuário e o conjunto de sistemas TCB.PRC <-SEG.PRC, se não permitido
        envie um reset e retorne.

          <SEQ = SEG.ACK> <CTL = RST>

        Se o SEG.PRC for menor que o TCB.PRC, continue.

        Defina RCV.NXT como SEG.SEQ + 1, o IRS está definido para SEG.SEQ e qualquer outro
        controle ou texto deve ser enfileirado para processamento posterior.  ISS
        deve ser selecionado e um segmento SYN enviado do formulário:

          <SEQ = ISS> <ACK = RCV.NXT> <CTL = SYN, ACK>

        SND.NXT está definido como ISS + 1 e SND.UNA como ISS. A conexão
        estado deve ser alterado para SYN-RECEIVED. Note que qualquer outro
        controle de entrada ou dados (combinados com SYN) serão processados
        no estado SYN-RECEIVED, mas o processamento de SYN e ACK deve
        não ser repetido. Se a escuta não foi totalmente especificada (ou seja,
        o soquete externo não foi totalmente especificado),
        campos não especificados devem ser preenchidos agora.

      quarto outro texto ou controle

        Qualquer outro segmento de controle ou de suporte a texto (que não contenha SYN)
        deve ter um ACK e, portanto, seria descartado pelo ACK
         em processamento. Um segmento RST de entrada não pode ser válido, uma vez que
        não poderia ter sido enviado em resposta a qualquer coisa enviada por este
        encarnação da conexão. Então é improvável que você chegue aqui
        mas se você fizer isso, solte o segmento e retorne.

    Se o estado for SYN-SENT, então

      primeiro verifique o bit ACK

        Se o bit ACK estiver definido

          Se SEG.ACK = <ISS, ou SEG.ACK> SND.NXT, envie um reset (a menos que
          o bit RST está definido, se assim for, solte o segmento e retorne)

            <SEQ = SEG.ACK> <CTL = RST>

          e descartar o segmento.  Retorna.

          Se SND.UNA = <SEG.ACK = <SND.NXT, o ACK é aceitável.

      segundo verifique o bit RST

[Pág. 66]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional
SEGMENTO CHEGA
        Se o bit RST estiver definido

          Se o ACK foi aceitável, sinalize ao usuário "erro:
          reset da conexão ", solte o segmento, insira o estado FECHADO,
          exclua TCB e retorne. Caso contrário (sem ACK), elimine o segmento
          e retorno.

      terceiro verifique a segurança e precedência

        Se a segurança / compartimento no segmento não for exatamente
        coincidir com a segurança / compartimento no TCB, enviar um reset

          Se houver um ACK

            <SEQ = SEG.ACK> <CTL = RST>

           De outra forma

            <SEQ = 0> <ACK = SEG.SEQ + SEG.LEN> <CTL = RST, ACK>

        Se houver um ACK

          A precedência no segmento deve corresponder à precedência no
          TCB, se não, envie um reset

            <SEQ = SEG.ACK> <CTL = RST>

        Se não houver ACK

          Se a precedência no segmento for maior que a precedência
          no TCB, em seguida, se permitido pelo usuário e o sistema aumentar
          a precedência no TCB para que no segmento, se não
          permissão para elevar o prec e enviar um reset.

            <SEQ = 0> <ACK = SEG.SEQ + SEG.LEN> <CTL = RST, ACK>

          Se a precedência no segmento for menor que a precedência
          no TCB continuar.

        Se uma redefinição foi enviada, descarte o segmento e retorne.

      quarta verificar o bit SYN

        Este passo só deve ser alcançado se o ACK estiver ok ou se houver
        nenhum ACK e o segmento não continha um RST.

        Se o bit SYN estiver ligado e a segurança / compartimento e precedência

 [Página 67]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional
                                                         SEGMENTO CHEGA

        são aceitáveis, o RCV.NXT é definido como SEG.SEQ + 1, o IRS é definido como
        SEG.SEQ. SND.UNA deve ser avançado para ser igual a SEG.ACK (se houver
        é um ACK) e quaisquer segmentos na fila de retransmissão que
        são assim reconhecidos devem ser removidos.

        Se SND.UNA> ISS (nosso SYN foi reconhecido), altere a conexão
        ESTABELECIDO, forma um segmento ACK

          <SEQ = SND.NXT> <ACK = RCV.NXT> <CTL = ACK>

        e enviá-lo. Dados ou controles que foram enfileirados
        transmissão pode ser incluída. Se houver outros controles ou
        texto no segmento, em seguida, continuar o processamento no sexto passo
        abaixo, onde o bit URG é verificado, caso contrário, retorne.

        Caso contrário, digite SYN-RECEIVED, forma um segmento SYN, ACK

          <SEQ = ISS> <ACK = RCV.NXT> <CTL = SYN, ACK>

        e enviá-lo. Se houver outros controles ou texto no
        segmento, enfileirá-los para processamento após o estado ESTABLISHED
        foi atingido, retorno.

      quinto, se nenhum dos bits SYN ou RST estiver definido, elimine
      segmento e retorno.

[Página 68]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional
SEGMENTO CHEGA
     De outra forma,

    primeiro número de seqüência de cheque

      ESTADO RECEBIDO
      ESTADO ESTABELECIDO
      FIN-WAIT-1 STATE
      FIN-WAIT-2 STATE
      ESTADO DE CLOSE-WAIT
      ESTADO DE FECHAMENTO
      ESTADO LAST-ACK
      ESTADO TIME-WAIT

        Os segmentos são processados ​​em sequência. Testes iniciais na chegada
        são usados ​​para descartar duplicatas antigas, mas o processamento adicional é
        feito na ordem SEG.SEQ. Se o conteúdo de um segmento se estender ao
        limite entre o antigo e o novo, apenas as novas partes devem ser
         processado.

        Existem quatro casos para o teste de aceitabilidade de uma entrada
        segmento:

        Teste de recebimento de segmento
        Janela Comprimento
        ------- ------- ------------------------------------ -------

           0 0 SEG.SEQ = RCV.NXT

           0> 0 RCV.NXT = <SEG.SEQ <RCV.NXT + RCV.WND

          > 0 0 não aceitável

          > 0> 0 RCV.NXT = <SEG.SEQ <RCV.NXT + RCV.WND
                      ou RCV.NXT = <SEG.SEQ + SEG.LEN-1 <RCV.NXT + RCV.WND

        Se o RCV.WND for zero, nenhum segmento será aceitável, mas
        deverá ser concedido um subsídio especial para aceitar ACKs, URGs e
        RSTs.

        Se um segmento de entrada não for aceitável, uma confirmação
        deve ser enviado em resposta (a menos que o bit RST esteja definido, se
        o segmento e retorno):

          <SEQ = SND.NXT> <ACK = RCV.NXT> <CTL = ACK>

        Depois de enviar a confirmação, elimine o segmento inaceitável
        e retorno.

 [Página 69]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional
                                SEGMENTO CHEGA

        A seguir, assume-se que o segmento é o idealizado
        segmento que começa no RCV.NXT e não excede a janela.
        Pode-se adaptar segmentos reais para se adequar a essa suposição
        aparar quaisquer partes que se encontrem do lado de fora da janela
        SYN e FIN), e só processando mais se o segmento então
        começa no RCV.NXT. Segmentos com maior sequência inicial
        números podem ser mantidos para processamento posterior.

    segundo verifique o bit RST,

      ESTADO RECEBIDO

        Se o bit RST estiver definido

          Se esta conexão foi iniciada com um OPEN passivo (ou seja,
          veio do estado LISTEN), então retorne esta conexão para
          OUÇA estado e retorno. O usuário não precisa ser informado. E se
          esta conexão foi iniciada com um OPEN ativo (ou seja, veio
          do estado SYN-SENT) então a conexão foi recusada, sinal
          o usuário "conexão recusada". Em ambos os casos, todos os segmentos
          na fila de retransmissão deve ser removido. E no
          caso OPEN ativo, insira o estado CLOSED e exclua o TCB,
          e retorno.

      ESTABELECIDO
      FIN-WAIT-1
      FIN-WAIT-2
      FECHAR-ESPERAR

        Se o bit RST estiver configurado, então, quaisquer RECEIVES pendentes e SEND
        deve receber respostas "reset". Todas as filas de segmento devem ser
        lavada. Os usuários também devem receber um aviso geral não solicitado
        sinal "reset de conexão". Digite o estado CLOSED, exclua o
        TCB e retorno.

      ESTADO DE FECHAMENTO
      ESTADO LAST-ACK
      TEMPO DE ESPERA

        Se o bit RST estiver definido, insira o estado FECHADO, exclua o
        TCB e retorno.

[Página 70]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional
SEGMENTO CHEGA
    terceira verificação de segurança e precedência

      SYN RECEBIDO

        Se a segurança / compartimento e precedência no segmento não
        corresponde exatamente a segurança / compartimento e precedência no TCB
        em seguida, envie uma redefinição e retorne.

      ESTADO ESTABELECIDO

        Se a segurança / compartimento e precedência no segmento não
        corresponde exatamente a segurança / compartimento e precedência no TCB
        então envie um reset, qualquer RECEIVE e SEND pendentes
        receber respostas "reset". Todas as filas de segmento devem ser
        lavada. Os usuários também devem receber um aviso geral não solicitado
        sinal "reset de conexão". Digite o estado CLOSED, exclua o
        TCB e retorno.

      Observe que esta verificação é feita após a verificação da seqüência para evitar
      um segmento de uma conexão antiga entre essas portas com um
      segurança diferente ou precedência de causar um aborto do
      conexão atual.

    quarta, verifique o bit SYN,

      SYN RECEBIDO
      ESTADO ESTABELECIDO
      FIN-WAIT STATE-1
      FIN-WAIT STATE-2
      ESTADO DE CLOSE-WAIT
      ESTADO DE FECHAMENTO
      ESTADO LAST-ACK
      ESTADO TIME-WAIT

        Se o SYN está na janela é um erro, envie um reset, qualquer
        RECEIVEs e SEND pendentes devem receber respostas "redefinidas",
        todas as filas de segmento devem ser liberadas, o usuário também deve
        receber um sinal geral "reset de conexão" não solicitado, digite
        o estado CLOSED, exclua o TCB e retorne.

        Se o SYN não estiver na janela, este passo não será alcançado
        e um ack teria sido enviado no primeiro passo (seqüência
        verificação do número).

 [Página 71]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional
                                                         SEGMENTO CHEGA

    quinto verifique o campo ACK,

      se o bit ACK estiver desligado, solte o segmento e retorne

      se o bit ACK estiver ativado

        ESTADO RECEBIDO

          Se SND.UNA = <SEG.ACK = <SND.NXT, insira o estado ESTABLISHED
          e continue processando.

            Se o reconhecimento do segmento não for aceitável, forme um
            segmento de reinicialização,

              <SEQ = SEG.ACK> <CTL = RST>

            e enviá-lo.

        ESTADO ESTABELECIDO

          Se SND.UNA <SEG.ACK = <SND.NXT, então, configure SND.UNA <- SEG.ACK.
          Quaisquer segmentos na fila de retransmissão que são, desse modo,
          inteiramente reconhecido são removidos. Os usuários devem receber
          confirmações positivas para buffers que foram SENT e
          totalmente confirmado (ou seja, o buffer de envio deve ser retornado
          resposta "ok"). Se o ACK for uma duplicata
          (SEG.ACK <SND.UNA), pode ser ignorado. Se o ack ACK
          algo ainda não enviado (SEG.ACK> SND.NXT) envie um ACK,
          solte o segmento e retorne.

          Se SND.UNA <SEG.ACK = <SND.NXT, a janela de envio deve ser
           Atualizada. Se (SND.WL1 <SEG.SEQ ou (SND.WL1 = SEG.SEQ e
          SND.WL2 = <SEG.ACK)), defina SND.WND <- SEG.WND, defina
          SND.WL1 <- SEG.SEQ e defina SND.WL2 <- SEG.ACK.

          Observe que SND.WND é um deslocamento de SND.UNA, que SND.WL1
          registra o número de seqüência do último segmento usado para atualizar
          SND.WND, e que SND.WL2 registra o número de reconhecimento de
          o último segmento usado para atualizar o SND.WND. O cheque aqui
          impede o uso de segmentos antigos para atualizar a janela.

[Página 72]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional
SEGMENTO CHEGA
        FIN-WAIT-1 STATE

          Além do processamento para o estado ESTABLISHED, se
          nosso FIN é agora reconhecido então entre no FIN-WAIT-2 e continue
          processamento nesse estado.

        FIN-WAIT-2 STATE

          Além do processamento para o estado ESTABLISHED, se
          a fila de retransmissão está vazia, o CLOSE do usuário pode ser
          reconhecido ("ok"), mas não exclua o TCB.

        ESTADO DE CLOSE-WAIT

          Faça o mesmo processamento do estado ESTABLISHED.

        ESTADO DE FECHAMENTO

          Além do processamento para o estado ESTABLISHED, se
          o ACK reconhece nosso FIN e entra no estado TIME-WAIT,
          caso contrário, ignore o segmento.

        ESTADO LAST-ACK

          A única coisa que pode chegar nesse estado é um
          reconhecimento do nosso FIN. Se nosso FIN for reconhecido agora,
          exclua o TCB, insira o estado CLOSED e retorne.

        ESTADO TIME-WAIT

          A única coisa que pode chegar nesse estado é um
          retransmissão do FIN remoto. Reconheça e reinicie
          o tempo limite de 2 MSL.

    sexto, verifique o bit URG,

      ESTADO ESTABELECIDO
      FIN-WAIT-1 STATE
      FIN-WAIT-2 STATE

        Se o bit URG estiver definido, RCV.UP <- max (RCV.UP, SEG.UP) e sinal
        o usuário que o lado remoto tem dados urgentes se o urgente
        ponteiro (RCV.UP) é antecipadamente dos dados consumidos.  Se o
        usuário já foi sinalizado (ou ainda está no estado "urgente").
        modo ") para esta sequência contínua de dados urgentes, não
        sinalizar o usuário novamente.

 [Pg 73]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional
                                SEGMENTO CHEGA

      ESTADO DE CLOSE-WAIT
      ESTADO DE FECHAMENTO
      ESTADO LAST-ACK
      TEMPO DE ESPERA

        Isso não deve ocorrer, uma vez que uma FIN foi recebida do
        lado remoto. Ignore o URG.

    sétimo, processe o texto do segmento,

      ESTADO ESTABELECIDO
      FIN-WAIT-1 STATE
      FIN-WAIT-2 STATE

        Uma vez no estado ESTABLISHED, é possível entregar o segmento
        texto para o usuário receber buffers. O texto dos segmentos pode ser movido
        em buffers até que o buffer esteja cheio ou o segmento esteja
         vazio. Se o segmento esvaziar e transportar um sinalizador PUSH,
        o usuário é informado, quando o buffer é retornado, que um PUSH
        foi recebido.

        Quando o TCP assume a responsabilidade de entregar os dados ao
        usuário também deve confirmar o recebimento dos dados.

        Uma vez que o TCP assume a responsabilidade pelos dados, ele avança
        RCV.NXT sobre os dados aceites e ajusta o RCV.WND como
        apropriado para a disponibilidade atual do buffer. O total de
        RCV.NXT e RCV.WND não devem ser reduzidos.

        Por favor, observe as sugestões de gerenciamento de janelas na seção 3.7 .

        Envie uma confirmação do formulário:

          <SEQ = SND.NXT> <ACK = RCV.NXT> <CTL = ACK>

        Este reconhecimento deve ser colocado em um segmento sendo
        transmitido, se possível, sem incorrer em atraso indevido.

[Página 74]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional
SEGMENTO CHEGA

      ESTADO DE CLOSE-WAIT
      ESTADO DE FECHAMENTO
      ESTADO LAST-ACK
      ESTADO TIME-WAIT

        Isso não deve ocorrer, uma vez que uma FIN foi recebida do
        lado remoto. Ignore o texto do segmento.

    oitavo, verifique o bit FIN

      Não processe o FIN se o estado estiver CLOSED, LISTEN ou SYN-SENT
      já que o SEG.SEQ não pode ser validado; soltar o segmento e
       Retorna.

      Se o bit FIN estiver definido, sinalize ao usuário "fechamento da conexão" e
      devolver quaisquer RECEIVOS pendentes com a mesma mensagem, avançar RCV.NXT
      sobre o FIN, e envie uma confirmação para o FIN.  Observe que
      FIN implica PUSH para qualquer texto de segmento ainda não entregue ao
      do utilizador.

        ESTADO RECEBIDO
        ESTADO ESTABELECIDO

          Digite o estado CLOSE-WAIT.

        FIN-WAIT-1 STATE

          Se o nosso FIN foi ACKed (talvez neste segmento), então
          entre com TIME-WAIT, inicie o temporizador de espera, desligue o outro
          temporizadores; caso contrário, insira o estado CLOSING.

        FIN-WAIT-2 STATE

          Digite o estado TIME-WAIT. Inicie o temporizador de espera, gire
          fora dos outros temporizadores.

        ESTADO DE CLOSE-WAIT

          Permaneça no estado CLOSE-WAIT.

        ESTADO DE FECHAMENTO

          Permaneça no estado CLOSING.

        ESTADO LAST-ACK

          Permaneça no estado LAST-ACK.
 [Pg 75]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Especificação funcional
                                SEGMENTO CHEGA

        ESTADO TIME-WAIT

          Permaneça no estado TIME-WAIT. Reinicie o tempo de espera de 2 MSL
          tempo esgotado.

    e retorno.

[Página 76]
 Setembro de 1981
                                            protocolo de Controle de Transmissão
                                                 Especificação funcional
TIMEOUT DO USUÁRIO

  TIMEOUT DO USUÁRIO

    Para qualquer estado se o tempo limite do usuário expirar, libere todas as filas, sinalize
    o usuário "erro: conexão abortada devido ao tempo limite do usuário" em geral
    e para quaisquer chamadas pendentes, exclua o TCB, insira o CLOSED
    estado e retorno.

  TIMEOUT DE RETRANSMISSÃO

    Para qualquer estado, se o tempo limite de retransmissão expirar em um segmento
    a fila de retransmissão, envie o segmento na frente do
    fila de retransmissão novamente, reinicialize o temporizador de retransmissão,
    e retorno.

  TIME-WAIT TIMEOUT

    Se o tempo limite de tempo de espera expirar em uma conexão, exclua o TCB,
    insira o estado CLOSED e retorne.

 [Pg 77]
 Setembro de 1981
 protocolo de Controle de TransmissãO

[Pág. 78]
 Setembro de 1981
                protocolo de Controle de Transmissão
                            GLOSSÁRIO
 1822
          Relatório da BBN 1822, "A Especificação da Interconexão de
          um Host e um IMP ". A especificação da interface entre um
          host e a ARPANET.

 ACK
          Um bit de controle (reconhecimento) que não ocupa espaço de seqüência,
          indica que o campo de confirmação deste segmento
          especifica o próximo número de sequência do remetente deste segmento
          está esperando receber, daí reconhecer o recebimento de todos
          números de sequência anteriores.

Mensagem ARPANET
          A unidade de transmissão entre um host e um IMP no
          ARPANET. O tamanho máximo é de cerca de 1012 octetos (8096 bits).

Pacote ARPANET
          Uma unidade de transmissão usada internamente na ARPANET entre
          IMPs. O tamanho máximo é de cerca de 126 octetos (1008 bits).

 conexão
          Um caminho de comunicação lógico identificado por um par de soquetes.

datagrama
          Uma mensagem enviada em um pacote de comunicações comutadas por computador
           rede.

 Endereço de Destino
          O endereço de destino, geralmente a rede e o host
          identificadores.

 FIN
          Um bit de controle (finis) ocupando um número de seqüência, que
          indica que o remetente não enviará mais dados ou controle
          ocupando espaço de seqüência.

 fragmento
          Uma parte de uma unidade lógica de dados, em particular uma
          fragmento é uma parte de um datagrama de internet.

 FTP
          Um protocolo de transferência de arquivos.

 [Página 79]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Glossário

 cabeçalho
          Controlar informações no início de uma mensagem, segmento,
          fragmento, pacote ou bloco de dados.

 hospedeiro
          Um computador. Em particular, uma fonte ou destino de mensagens
          do ponto de vista da rede de comunicação.

 Identificação
          Um campo de protocolo da Internet. Este valor de identificação atribuído
          pelo remetente ajuda na montagem dos fragmentos de um datagrama.

 criança levada
          O Processador de Mensagens da Interface, o comutador de pacotes do
          ARPANET.

endereço de internet
          Um endereço de origem ou destino específico para o nível do host.

datagrama de internet
          A unidade de dados trocada entre um módulo de internet e o
          protocolo de nível superior em conjunto com o cabeçalho da Internet.

fragmento de internet
          Uma parte dos dados de um datagrama de internet com uma internet
           cabeçalho.

 IP
          Protocolo de internet.

 IRS
          O número da sequência de recepção inicial. A primeira seqüência
          número usado pelo remetente em uma conexão.

 ISN
          O número da sequência inicial. O primeiro número de sequência usado
          em uma conexão (ISS ou IRS). Selecionado em um relógio
          procedimento baseado.

 ISS
          O número inicial da sequência de envio. O primeiro número de sequência
          usado pelo remetente em uma conexão.

 líder
          Controlar informações no início de uma mensagem ou bloco de
           dados. Em particular, na ARPANET, a informação de controle
          em uma mensagem ARPANET na interface host-IMP.

[Página 80]
 Setembro de 1981
                            protocolo de Controle de Transmissão
                                        Glossário

seqüência esquerda
          Este é o próximo número de seqüência a ser reconhecido pelo
          TCP de recebimento de dados (ou o menor atualmente não reconhecido)
          número de sequência) e é por vezes referido como a margem esquerda
          da janela de envio.

pacote local
          A unidade de transmissão dentro de uma rede local.

 módulo
          Uma implementação, geralmente em software, de um protocolo ou outro
           procedimento.

 MSL
          Vida útil máxima do segmento, a hora em que um segmento TCP pode existir
          o sistema de internetwork. Arbitrariamente definido como sendo 2 minutos.

octeto
          Um byte de oito bits.

 Opções
          Um campo Opção pode conter várias opções e cada opção
          pode ter vários octetos de comprimento. As opções são usadas
          principalmente em situações de teste; por exemplo, para transportar
          timestamps. Tanto o Protocolo da Internet quanto o TCP fornecem
          campos de opções.

 pacote
          Um pacote de dados com um cabeçalho que pode ou não ser
          logicamente concluído. Mais frequentemente, uma embalagem física do que uma
          empacotamento lógico de dados.

 porta
          A parte de um soquete que especifica qual entrada lógica ou
          canal de saída de um processo está associado aos dados.

 processo
          Um programa em execução. Uma fonte ou destino de dados de
          ponto de vista do protocolo TCP ou outro protocolo host-to-host.

EMPURRAR
          Um bit de controle que não ocupa espaço de seqüência, indicando que
          este segmento contém dados que devem ser enviados para o
          recebendo o usuário.

RCV.NXT
          recebe o próximo número de sequência

 [Pág. 81]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Glossário

RCV.UP
          recebe um ponteiro urgente

RCV.WND
          receber janela

recebe o próximo número de sequência
          Este é o próximo número de seqüência que o TCP local está esperando
           receber.

receber janela
          Isto representa a seqüência numera o TCP local (receptor)
          está disposto a receber. Assim, o TCP local considera que
          segmentos que se sobrepõem ao intervalo RCV.NXT
          RCV.NXT + RCV.WND - 1 transportam dados ou controle aceitáveis.
          Segmentos contendo números de sequência inteiramente fora deste
          intervalo são considerados duplicados e descartados.

RST
          Um bit de controle (reset), não ocupando espaço de seqüência, indicando
          que o receptor deve excluir a conexão sem mais
           interação. O receptor pode determinar, com base no
          número de sequência e campos de confirmação da entrada
          segmento, se deve honrar o comando reset ou ignorar
           isto. Em nenhum caso a recepção de um segmento contendo RST
          subir para um RST em resposta.

 RTP
          Protocolo em Tempo Real: Um protocolo host-para-host para comunicação
          de tempo de informação crítica.

SEG.ACK
          reconhecimento de segmento

SEG.LEN
          comprimento do segmento

SEG.PRC
          valor de precedência de segmento

SEG.SEQ
          sequência de segmentos

SEG.UP
          campo de ponteiro urgente do segmento

[Página 82]
 Setembro de 1981
                                    protocolo de Controle de Transmissão
                                                Glossário
SEG.WND
          campo da janela do segmento

 segmento
          Uma unidade lógica de dados, em particular um segmento TCP, é o
          unidade de dados transferidos entre um par de módulos TCP.

reconhecimento de segmento
          O número de sequência no campo de confirmação do
          segmento de chegada.

comprimento do segmento
          A quantidade de espaço numérico de seqüência ocupada por um segmento,
          incluindo quaisquer controles que ocupam espaço de seqüência.

sequência de segmentos
          O número no campo de sequência do segmento que chega.

enviar sequência
          Este é o próximo número de seqüência que o TCP local (emissor)
          use na conexão. Ele é inicialmente selecionado de uma
          curva de número de sequência inicial (ISN) e é incrementada para
          cada octeto de dados ou controle sequenciado transmitido.

enviar janela
          Isso representa os números de seqüência que o controle remoto
          (recebendo) TCP está disposto a receber. É o valor do
          campo de janela especificado em segmentos do controle remoto
          receber) TCP. O intervalo de novos números de sequência que podem
          ser emitido por um TCP situa-se entre SND.NXT e
          SND.UNA + SND.WND - 1. (Retransmissões de números de sequência
          entre SND.UNA e SND.NXT são esperados, é claro.)

SND.NXT
          enviar sequência

SND.UNA
          seqüência esquerda

SND.UP
          enviar ponteiro urgente

SND.WL1
          número de sequência do segmento na última atualização da janela

SND.WL2
          número de confirmação do segmento na última atualização da janela

 [Página 83]
 Setembro de 1981
 protocolo de Controle de Transmissão
 Glossário

SND.WND
          enviar janela

 soquete
          Um endereço que inclui especificamente um identificador de porta,
          é a concatenação de um endereço da Internet com uma porta TCP.

 Endereço de Origem
          O endereço de origem, geralmente os identificadores de rede e host.

 SYN
          Um bit de controle no segmento de entrada, ocupando uma sequência
          número, usado no início de uma conexão, para indicar
          onde a numeração da seqüência será iniciada.

TCB
          Bloco de controle de transmissão, a estrutura de dados que registra
          o estado de uma conexão.

TCB.PRC
          A precedência da conexão.

 TCP
          Protocolo de Controle de Transmissão: Um protocolo de host para host para
          comunicação confiável em ambientes de internetwork.

 TOS
          Tipo de serviço, um campo de protocolo da Internet.

Tipo de serviço
          Um campo de protocolo da Internet que indica o tipo de serviço
          para este fragmento de internet.

 URG
          Um bit de controle (urgente), sem espaço de seqüência, usado para
          indicam que o usuário receptor deve ser notificado para fazer
          processamento urgente, desde que haja dados a serem consumidos
          números de seqüência menores do que o valor indicado no urgente
           ponteiro.

ponteiro urgente
          Um campo de controle significativo apenas quando o bit URG está ativado.  este
          campo comunica o valor do ponteiro urgente que
          indica o octeto de dados associado ao usuário emissor
          chamada urgente.

[Página 84]
 Setembro de 1981
                  protocolo de Controle de Transmissão
                                REFERÊNCIAS

[ 1 ] Cerf, V. e R. Kahn, "Um Protocolo para Rede de Pacotes
     Intercomunicação ", IEEE Transactions on Communications,
      Vol. COM-22, No. 5, pp 637-648, maio de 1974.

[ 2 ] Postel, J. (ed.), "Protocolo de Internet - Programa de Internet DARPA
     Especificação do Protocolo ", RFC 791 , USC / Ciências da Informação
     Instituto, setembro de 1981.

[ 3 ] Dalal, Y. e C. Sunshine, "Gerenciamento de Conexão em Transporte
     Protocolos ", Computer Networks, Vol. 2, No. 6, pp. 454-473,
     Dezembro de 1978.

[ 4 ] Postel, J., "números atribuídos", RFC 790 , USC / Ciências da Informação
     Instituto, setembro de 1981.



                                                               [Página 85]

*/

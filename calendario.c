#include <stdio.h>

// Função para determinar se o ano é Bissexto

int anoBissexto(int ano){
  return(ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

// Função de imprimir mês do calendário

void imprimirMes(int primeiroDia, int diasNoMes){
  printf(" DOM SEG TER QUA QUI SEX SÁB\n");
  int dia = 1, i;
  //Alinhar os dias
  for(i=0;i<primeiroDia;i++){
    printf("  ");
  }
  //Imprimir os dias
  for(i=primeiroDia;i<7;i++){
    printf("%3d ",dia++);
  }
  printf("\n");
  while(dia<=diasNoMes){
    for(i=0,i<7 && dia<= diasNoMes;i++){
      printf("%3d ",dia++);
    }
    printf("\n");
  }
}

// Mostrar Calendário

void mostrarCalendario(int primeiroDia, int anoBissexto){
  char *meses[] = {"Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};
  int diasNoMes[] = {31, anoBissexto ? 29 : 28 31 30 31 30 31 31 30 31 30 31};
  int i;
  printf("***CALENDÁRIO***\n");
  for(i=0; i<12;i++){
    printf("\n%s\n",meses[i]);
    imprimirMes(primeiroDia, diasNoMes[i];
    primeiroDia = (primeiroDia + diasNoMes[i]) % 7;
  }
}

// Mostrar Calendário com Agendamentos

void mostrarCalendarioComAgendamentos(int primeiroDia, int anoBissexto, int agenda[]){
  char *meses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
  int diasNoMes[] = {31, anoBissexto ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int i, j;
  printf("\n*** CALENDÁRIO DE AGENDAMENTOS ***\n");
  for (i = 0; i < 12; i++) {
    int dia = 1;
    printf("\n%s\n", meses[i]);
    printf("Dom Seg Ter Qua Qui Sex Sab\n");
    for (j = 0; j < primeiroDia; j++) {
        printf("    ");
    }
    for (j = primeiroDia; j < 7; j++) {
        printf("%3d ", agenda[dia++]);
    }
    printf("\n");
    while (dia <= diasNoMes[i]) {
      for (j = 0; j < 7 && dia <= diasNoMes[i]; j++) {
        printf("%3d ", agenda[dia++]);
      }
      printf("\n");
    }
    primeiroDia = (primeiroDia + diasNoMes[i]) % 7;
  }
}

// Inserir agendamentos

void inserirAgendamentos(int agenda[], int primeiroDia, int anoBissexto){
  char *meses[] = {"Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};
  int diasNoMes[] = {31, anoBissexto ? 29 : 28 31 30 31 30 31 31 30 31 30 31};

  int mes, dia, duracao;
  printf("Insira o mês (1-12): ");
    scanf("%d", &mes);
  printf("Insira o dia (1-%d): ", diasNoMes[mes - 1]);
    scanf("%d", &dia);
  printf("Insira a duração do agendamento: ");
    scanf("%d", &duracao);

  if(dia + duracao - 1 > diaNoMes[mes -1]) {
    printf("A duração do agendamento ultrapassa o fim do mês. \n", i, meses[mes - 1]);
    return;
  }

  int i, count = 0;
  for(i = dia; i<dia+duracao;i++){
    if(agenda[i] >=5){
      printf("Conflito de agendamento no dia %d de %s.\n",i, meses[mes - 1]);
      return;
    }
    count++;
  }
  for(i=dia;i<dia+duracao;i++){
    agenda[i];
  }
  printf("%d agendamento(s) inserido(s) para o(s) dia(s) %d-%d de %s.\n",count,dia,dia+duracao-1,meses[mes-1]);
}

int main(){
  int primeiroDia, anoBissexto;
  printf("Insira o dia da semana em que 1º de Janeiro cai(0 para domingo, 1 para segunda...6 para sábado):");
    scanf("%d", &primeiroDia);
  printf("O ano é Bissexto?(1 para Sim, 0 para Não):");
    scanf("%d", &anoBissexto);
  int agenda[366] = {0} 
  int escolha;
  do{
    printf("\nMenu:\n");
    printf("1. Mostrar Calendário\n");
    printf("2. Inserir Agendamentos\n");
    printf("3. Mostrar Calendário com Agendamentos\n");
    printf("4. Sair\n");
    printf("Escolha uma opção:");
      scanf("%d", &escolha);
    switch(escolha){
      case 1:
        mostrarCalendario(primeiroDia, anoBissexto);
        break;
      case 2:
        inserirAgendamento(agenda, primeiroDia, anoBissexto);
        break;
      case 3: 
        mostrarCalendarioComAgendamentos(primeiroDia, anoBissexto, agenda);
        break;
      case 4:
        printf("Saindo\n");
        break;
      default:
        printf("Opção Inválida.\n");
    }
  } while (escolha != 4);
  return 0;
}


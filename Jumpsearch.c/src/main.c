#include <stdio.h>
#include <stdlib.h>
#include "aluno.c"

int main(void)
{
    int controle, totaldealunos = 0, j;
    Aluno *alunotemporario;
    FILE *arquivo;
    char caminho[] = "C:\\Users\\jhoan\\Desktop\\VScode\\GitHub\\JumpSearch\\Jumpsearch.c\\data\\aluno.txt"; // caminho do arquivo txt(Varia de pc para pc)
    arquivo = fopen(caminho, "r");
    Aluno *alunos = (Aluno *)malloc(sizeof(Aluno)); // alocando dinamicamente
    alunos = NULL;                                  // inicializnando o "vetor aluno"
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!");
        return 1;
    }
    printf("Bem-vindo ao Programa de Gerenciamento de Alunos!\nAutores: Jhoan,Abner,Caio,Tomaz\t\tVersao:1.0\n\n");
    while (controle != 6) // vai repetir ate o usuario digitar 6
    {
        printf("Menu:\n1-Atualizar sistema\n2-Listar Alunos\n3-Matricular alunos\n4-Buscar aluno por matricula\n5-Buscar aluno pelo nome\n6-Sair\n\nDigite sua opcao: ");
        scanf("%d", &controle);
        system("cls");
        switch (controle)
        {
        case 1:
            alunos = lerArquivo(alunos, caminho, &totaldealunos);
            printf("Atualizado!\n\n");
            break;
        case 2:
            ListarAlunos(alunos, totaldealunos);
            break;
        case 3:
            cadastrarAluno(arquivo, caminho);
            break;
        case 4:
            alunotemporario = BuscarAlunoPelaMatricula(alunos, totaldealunos);
            if (alunotemporario != NULL)
            {
                printf("\nAluno Encontrado!\n\n");
                printf("Nome: %s\n", alunotemporario->nome);
                printf("Matricula: %d\n", alunotemporario->matricula);
                printf("Notas: ");
                for (j = 0; j < 3; j++)
                {
                    printf("%.1f ", alunotemporario->notas[j]);
                }
                printf("\nMedia: %.1f\n\n", alunotemporario->media);
            }
            else
            {
                printf("Aluno Nao foi encontrado!\n\n");
            }
            break;
        case 5:
            alunotemporario = BuscarAlunoPeloNome(alunos, totaldealunos);
            if (alunotemporario != NULL)
            {
                printf("\nAluno Encontrado!\n\n");
                printf("Nome: %s\n", alunotemporario->nome);
                printf("Matricula: %d\n", alunotemporario->matricula);
                printf("Notas: ");
                for (j = 0; j < 3; j++)
                {
                    printf("%.1f ", alunotemporario->notas[j]);
                }
                printf("\nMedia: %.1f\n\n", alunotemporario->media);
            }
            else
            {
                printf("Aluno Nao foi encontrado!\n\n");
            }
            break;
        case 6:
            printf("Obrigado por usar meu programa!");
            break;
        default:
            printf("opcao invalida!");
            break;
        }
    }
    fclose(arquivo);
    free(alunos);
    return 0;
}
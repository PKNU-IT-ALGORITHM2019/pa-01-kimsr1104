#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD 176050					// dict.txt�� �ܾ� ����

typedef struct Word {					// ����ü �迭 ����
	char word[20];						// �ܾ�
	char word_class[20];				// ǰ��
	char description[];					// ����
}Word;

int find(Word *arr[], char *target, int begin, int end);		// find �Լ� ����

int main()
{
	Word *wd[MAX_WORD] = { NULL };
	for (int i = 0; i < MAX_WORD; i++)
		wd[i] = (Word*)malloc(sizeof(Word));		// ���� �޸� �Ҵ�
	FILE *file = fopen("dict.txt", "rt");			// dict.txt ���� �б�
	/*	if (dict���� ���� �д� ���� "\n\n"�� ������)
			�� �ڷ� " " �� ���������� wd->word�� ���ڿ� ���� => �ܾ�
		if (" " ���� "("���� ")"����)
			���ڿ��� wd->word_class�� ���� => ǰ��
		if (���� "\n\n"�� ����)
			wd->description�� ���� => ����	*/
	// �� ������ �������� ���߽��ϴ�.

	char Search_word[20];							// �˻� �� �ܾ�

	printf("�˻� �� �ܾ� : ");
	scanf("%s", &Search_word);

	find(wd, Search_word, 0, MAX_WORD);				// ���� Ž�� �Լ�, �ε��� ���� : 0 ~ MAX_WORD

	if (find(wd, Search_word, 0, MAX_WORD) == -1)		// ã�� ���� ���, �Ʒ� else ������ �ּ�ó�� �� �����ϸ� ���� ����
		printf("������ ã�� �ܾ �����ϴ�.\n");
	else									// find �Լ����� ���Ϲ��� mid���� �����ϴ� ����� �𸣰ڽ��ϴ�.
	{												// �ߺ��Ǵ� �ܾ � �ִ��� �˻�
		int count = 1;
		while (1)
		{
			if (wd[mid]->word == wd[mid+1]->word)
			{
				mid = mid + 1;
			}
			else
				break;
		}
		while (1)
		{
			if (wd[mid]->word == wd[mid - 1]->word)
			{
				mid = mid - 1;
				count++;
			}
			else
			{
				printf("%d���� �ܾ ã�ҽ��ϴ�.\n", count);
				break;
			}
		}
		for (int i = mid; i < mid + count; i++)
		{
			printf("%s %s %s\n", wd[mid]->word, wd[mid]->word_class, wd[mid]->description);
		}
	}
	return 0;
}

int find(Word *arr[], char *target, int begin, int end)
{
	if (begin > end)
		return -1;
	else
	{
		int mid = (begin + end) / 2;
		if (arr[mid]->word == target)
			return mid;
		else if (arr[mid]->word > target)
			return find(arr, target, begin, mid - 1);
		else
			return find(arr, target, mid + 1, end);					// ��ȯ����, �ð����⵵ : O(log N)
	}
}
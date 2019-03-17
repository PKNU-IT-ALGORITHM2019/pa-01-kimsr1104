#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD 176050					// dict.txt의 단어 갯수

typedef struct Word {					// 구조체 배열 정의
	char word[20];						// 단어
	char word_class[20];				// 품사
	char description[];					// 설명
}Word;

int find(Word *arr[], char *target, int begin, int end);		// find 함수 선언

int main()
{
	Word *wd[MAX_WORD] = { NULL };
	for (int i = 0; i < MAX_WORD; i++)
		wd[i] = (Word*)malloc(sizeof(Word));		// 동적 메모리 할당
	FILE *file = fopen("dict.txt", "rt");			// dict.txt 파일 읽기
	/*	if (dict에서 값을 읽는 도중 "\n\n"을 만나면)
			그 뒤로 " " 를 만날때까지 wd->word에 문자열 저장 => 단어
		if (" " 이후 "("부터 ")"까지)
			문자열을 wd->word_class에 저장 => 품사
		if (이후 "\n\n"전 까지)
			wd->description에 저장 => 설명	*/
	// 위 내용은 구현하지 못했습니다.

	char Search_word[20];							// 검색 할 단어

	printf("검색 할 단어 : ");
	scanf("%s", &Search_word);

	find(wd, Search_word, 0, MAX_WORD);				// 이진 탐색 함수, 인덱스 범위 : 0 ~ MAX_WORD

	if (find(wd, Search_word, 0, MAX_WORD) == -1)		// 찾지 못한 경우, 아래 else 구문을 주석처리 후 수행하면 정상 동작
		printf("사전에 찾는 단어가 없습니다.\n");
	else									// find 함수에서 리턴받은 mid값을 적용하는 방법을 모르겠습니다.
	{												// 중복되는 단어가 몇개 있는지 검사
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
				printf("%d개의 단어를 찾았습니다.\n", count);
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
			return find(arr, target, mid + 1, end);					// 순환구조, 시간복잡도 : O(log N)
	}
}
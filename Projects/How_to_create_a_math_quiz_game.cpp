
// Question: How to create a math quiz game in C++?

#include<iostream>
using namespace std;
enum enQuestionsLevel { EasyLevel = 1, MedLevel = 2, HardLevel =
3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp
= 5 };
string GetOpTypeSymbol(enOperationType OpType)
{
switch (OpType)
{
case enOperationType::Add:
return "+";
case enOperationType::Sub:
return "-";
case enOperationType::Mult:
return "x";
case enOperationType::Div:
return "/";
default:
return "Mix";
}
}
string GetQuestionLevelText(enQuestionsLevel QuestionLevel)
{
string arrQuestionLevelText[4] = { "Easy","Med","Hard","Mix"
};
return arrQuestionLevelText[QuestionLevel - 1];
}
int RandomNumber(int From, int To)
{
//Function to generate a random number
int randNum = rand() % (To - From + 1) + From;
return randNum;
}
void SetScreenColor(bool Right)
{
if (Right)
system("color 2F"); //turn screen to Green
else
{
system("color 4F"); //turn screen to Red
cout << "\a";
}
}
short ReadHowManyQuestions()
{
short NumberOfQuestions;
do
{
cout << "How Many Questions do you want to answer ? ";
cin >> NumberOfQuestions;
} while (NumberOfQuestions < 1 || NumberOfQuestions >10);
return NumberOfQuestions;
}
enQuestionsLevel ReadQuestionsLevel()
{
short QuestionLevel = 0;
do
{
cout << "Enter Questions Level [1] Easy, [2] Med, [3]
Hard, [4] Mix ? ";
cin >> QuestionLevel;
} while (QuestionLevel < 1 || QuestionLevel >4);
return (enQuestionsLevel) QuestionLevel;
}
enOperationType ReadOpType()
{
short OpType;
do
{
cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul,
[4] Div, [5] Mix ? ";
cin >> OpType;
} while (OpType < 1 || OpType >5);
return (enOperationType) OpType;
}
struct stQuestion
{
int Number1 = 0;
int Number2 = 0;
enOperationType OperationType;
enQuestionsLevel QuestionLevel;
int CorrectAnswer = 0;
int PlayerAnswer = 0;
bool AnswerResult = false;
};
struct stQuizz
{
stQuestion QuestionList[100];
short NumberOfQuestions;
enQuestionsLevel QuestionsLevel;
enOperationType OpType;
short NumberOfWrongAnswers = 0;
short NumberOfRightAnswers = 0;
bool isPass = false;
};
int SimpleCalculator(int Number1, int Number2, enOperationType
OpType)
{
switch (OpType)
{
case enOperationType::Add:
return Number1 + Number2;
case enOperationType::Sub:
return Number1 - Number2;
case enOperationType::Mult:
return Number1 * Number2;
case enOperationType::Div:
return Number1 / Number2;
default:
return Number1 + Number2;
}
}
enOperationType GetRandomOperationType()
{
int Op = RandomNumber(1, 4);
return (enOperationType)Op;
}
stQuestion GenerateQuestion(enQuestionsLevel QuestionLevel,
enOperationType OpType)
{
stQuestion Question;
if (QuestionLevel == enQuestionsLevel::Mix)
{
QuestionLevel = (enQuestionsLevel) RandomNumber(1, 3);
}
if (OpType == enOperationType::MixOp)
{
OpType = GetRandomOperationType();
}
Question.OperationType = OpType;
switch (QuestionLevel)
{
case enQuestionsLevel::EasyLevel:
Question.Number1 = RandomNumber(1, 10);
Question.Number2 = RandomNumber(1, 10);
Question.CorrectAnswer =
SimpleCalculator(Question.Number1, Question.Number2,
Question.OperationType);
Question.QuestionLevel = QuestionLevel;
return Question;
case enQuestionsLevel::MedLevel:
Question.Number1 = RandomNumber(10, 50);
Question.Number2 = RandomNumber(10, 50);
Question.CorrectAnswer =
SimpleCalculator(Question.Number1, Question.Number2,
Question.OperationType);
Question.QuestionLevel = QuestionLevel;
return Question;
case enQuestionsLevel::HardLevel:
Question.Number1 = RandomNumber(50, 100);
Question.Number2 = RandomNumber(50, 100);
Question.CorrectAnswer =
SimpleCalculator(Question.Number1, Question.Number2,
Question.OperationType);
Question.QuestionLevel = QuestionLevel;
return Question;
}
return Question;
}
void GenerateQuizzQuestions(stQuizz& Quizz)
{
for (short Question = 0; Question < Quizz.NumberOfQuestions;
Question++)
{
Quizz.QuestionList[Question] =
GenerateQuestion(Quizz.QuestionsLevel, Quizz.OpType);
}
}
void PlayMathGame()
{
stQuizz Quizz;
Quizz.NumberOfQuestions = ReadHowManyQuestions();
Quizz.QuestionsLevel = ReadQuestionsLevel();
Quizz.OpType = ReadOpType();
GenerateQuizzQuestions(Quizz);
}
int main()
{
srand((unsigned)time(NULL));
PlayMathGame();
return 0;
}

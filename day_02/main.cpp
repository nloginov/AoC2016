#include <tuple>

enum direction {
  X = 0,
  L = 1,
  R = 2,
  U = 4,
  D = 8
};

static constexpr char first_task_abc[][3] = {
        {'7','8','9'},
        {'4','5','6'},
        {'1','2','3'}};


static constexpr int first_task_allowed_directions[][3] = {
        { U|R  , L|U|R  , L|U  },
        { U|R|D, L|U|R|D, L|U|D},
        { R|D  , L|R|D  , L|D  }};

static constexpr char second_task_abc[][5] = {
        {'0','0','D','0','0'},
        {'0','A','B','C','0'},
        {'5','6','7','8','9'},
        {'0','2','3','4','0'},
        {'0','0','1','0','0'}};

static constexpr int second_task_allowed_directions[][5] = {
        { X, X      , U      , X      , X},
        { X, U|R    , L|U|R|D, L|U    , X},
        { R, L|U|R|D, L|U|R|D, L|U|R|D, L},
        { X, R|D    , L|U|R|D, L|D    , X},
        { X, X      , D      , X      , X}};


static constexpr char input[][600] = {
    "RRLUDDLDUDUDUDRDDDRDDRLUUUDRUDURURURLRDDULLLDRRRRULDDRDDURDLURLURRUULRURDDDDLDDRRLDUDUUDURURDLDRRURDLLLDLLRUDRLDDRUULLLLLRRLDUDLUUDRUULLRLLLRLUURDLDLLDDRULDLUURRURLUUURLLDDULRDULULRULDDLRDDUUDLRRURLLURURLDDLURRLUURRRRLDRDLDUDRUDDRULLDUDDLRRLUUUUUDDLLDRLURDDRLLUDULDRDDLLUURUUUURDRLRLLULUULULLRRDLULRUDURDLRLRDDDRULLUULRURULLLUDUURUUUURUULDURDRRRULRLULDLRRULULUUDDDRDURLLURLLDUUUUDULRDLRDUUDDLDUDRLLRLRRRLULUDDDURLRRURUDDDRDRDRLLRDRDLDDRRDRDLLRLLLRRULRDDURRDUDRURDLDULLRRLURLRLLDURRRLLDRRURRRUULDRLDUULRDLDLURUDLLDLLUUDDDUUUDRL",
    "DLRRDRRDDRRDURLUDDDDDULDDLLDRLURDDDDDDRDDDRDDDLLRRULLLRUDULLDURULRRDLURURUDRUURDRLUURRUDRUULUURULULDDLLDDRLDUDDRDRDDUULDULDDLUDUDDUDLULLUDLLLLLRRRUURLUUUULRURULUDDULLLRLRDRUUULULRUUUULRDLLDLDRDRDRDRRUUURULDUUDLDRDRURRUDDRLDULDDRULRRRLRDDUUDRUDLDULDURRDUDDLULULLDULLLRRRDULLLRRURDUURULDRDURRURRRRDLDRRUDDLLLDRDRDRURLUURURRUUURRUDLDDULDRDRRURDLUULDDUUUURLRUULRUURLUUUDLUDRLURUDLDLDLURUURLDURDDDDRURULLULLDRDLLRRLDLRRRDURDULLLDLRLDR",
    "URURLLDRDLULULRDRRDDUUUDDRDUURULLULDRLUDLRUDDDLDRRLURLURUUDRLDUULDRDURRLLUDLDURRRRLURLDDRULRLDULDDRRLURDDRLUDDULUDULRLDULDLDUDRLLDDRRRDULLDLRRLDRLURLUULDDDDURULLDLLLDRRLRRLLRDDRDLDRURRUURLLDDDLRRRRRDLRRDRLDDDLULULRLUURULURUUDRULRLLRDLDULDRLLLDLRRRUDURLUURRUDURLDDDRDRURURRLRRLDDRURULDRUURRLULDLUDUULDLUULUDURRDDRLLLRLRRLUUURRDRUULLLRUUURLLDDRDRULDULURRDRURLRRLRDURRURRDLDUDRURUULULDDUDUULDRDURRRDLURRLRLDUDRDULLURLRRUDLUDRRRULRURDUDDDURLRULRRUDUUDDLLLURLLRLLDRDUURDDLUDLURDRRDLLRLURRUURRLDUUUUDUD",
    "DRRDRRRLDDLDUDRDLRUUDRDUDRRDUDRDURRDDRLLURUUDRLRDDULLUULRUUDDRLDLRULDLRLDUDULUULLLRDLURDRDURURDUDUDDDRRLRRLLRULLLLRDRDLRRDDDLULDLLUUULRDURRULDDUDDDURRDRDRDRULRRRDRUDLLDDDRULRRLUDRDLDLDDDLRLRLRLDULRLLRLRDUUULLRRDLLRDULURRLDUDDULDDRLUDLULLRLDUDLULRDURLRULLRRDRDDLUULUUUULDRLLDRDLUDURRLLDURLLDDLLUULLDURULULDLUUDLRURRRULUDRLDRDURLDUDDULRDRRDDRLRRDDRUDRURULDRRLUURUDULDDDLRRRRDRRRLLURUURLRLULUULLRLRDLRRLLUULLDURDLULURDLRUUDUUURURUURDDRLULUUULRDRDRUUDDDRDRL",
    "RLRUDDUUDDDDRRLRUUDLLDRUUUDRRDLDRLRLLDRLUDDURDLDUDRRUURULLRRLUULLUDRDRUDDULRLLUDLULRLRRUUDLDLRDDDRDDDUDLULDLRRLUDUDDRRRRDRDRUUDDURLRDLLDLDLRRDURULDRLRRURULRDDLLLRULLRUUUDLDUURDUUDDRRRDDRLDDRULRRRDRRLUDDDRUURRDRRDURDRUDRRDLUDDURRLUDUDLLRUURLRLLLDDURUDLDRLRLLDLLULLDRULUURLDDULDDRDDDURULLDRDDLURRDDRRRLDLRLRRLLDLLLRDUDDULRLUDDUULUDLDDDULULDLRDDLDLLLDUUDLRRLRDRRUUUURLDLRRLDULURLDRDURDDRURLDLDULURRRLRUDLDURDLLUDULDDU"
};


template <size_t N, typename TValues, typename TDirections>
constexpr std::tuple<int, int, char> find_digit(int x, int y, const char (&input)[N], TValues values, TDirections directions) {
  for(size_t i = 0; i < N; ++i) {
    if (input[i] == 'L' && (L & directions[x][y])) {
    	y--;
    }
    else if (input[i] == 'R' && (R & directions[x][y])) {
    	y++;
    }
    else if (input[i] == 'U' && (U & directions[x][y])) {
    	x++;
    }
    else if (input[i] == 'D' && (D & directions[x][y])) {
    	x--;
    }
  }
  return std::make_tuple(x, y, values[x][y]);
}

template <typename TValues, typename TDirections>
constexpr std::tuple<char, char, char, char, char> find_result(int x, int y, TValues values, TDirections directions) {
  char result[5] = {0};
  for (size_t i = 0; i < 5; ++i) {
    const auto answer = find_digit(x, y, input[i], values, directions);
    result[i] = std::get<2>(answer);
    x = std::get<0>(answer);
    y = std::get<1>(answer);
  }

  return std::make_tuple(result[0], result[1], result[2], result[3], result[4]);
}
static constexpr auto first_answer_tuple = find_result(1,1, first_task_abc, first_task_allowed_directions);
static constexpr auto second_answer_tuple = find_result(2,0, second_task_abc, second_task_allowed_directions);

int main()
{
    constexpr char first_answer[] = {
            '|',
            std::get<0>(first_answer_tuple),
            std::get<1>(first_answer_tuple),
            std::get<2>(first_answer_tuple),
            std::get<3>(first_answer_tuple),
            std::get<4>(first_answer_tuple)
    };
    constexpr char  second_answer[] = {
            '|',
            std::get<0>(second_answer_tuple),
            std::get<1>(second_answer_tuple),
            std::get<2>(second_answer_tuple),
            std::get<3>(second_answer_tuple),
            std::get<4>(second_answer_tuple)
    };
}
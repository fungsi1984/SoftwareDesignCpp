#include "Team.h"

Team_1::Team_1() : Team("TEAM 1")
{
    players[0] = new Player(12436, "Alwin", "Jim");
    players[1] = new Player(26410, "Bond", "Bob");
    players[2] = new Player(14306, "Charles", "Ronda");
    players[3] = new Player(61835, "Dunn", "Fred");
    players[4] = new Player(30437, "Edwards", "Gina");
    players[5] = new Player(76517, "Fanning", "Pat");
    players[6] = new Player(98734, "Galway", "Leslie");
    players[7] = new Player(14998, "Hiroshi", "Scott");
    players[8] = new Player(47303, "Ingles", "Mary");
}

Team_2::Team_2() : Team("TEAM 2")
{
    players.push_back(new Player(12436, "Jackson", "Tammy"));
    players.push_back(new Player(44551, "Killebrew", "Wally"));
    players.push_back(new Player(14306, "Lamprey", "Roberta"));
    players.push_back(new Player(61835, "Mays", "Serena"));
    players.push_back(new Player(30437, "Norton", "Donna"));
    players.push_back(new Player(76517, "OBrien", "George"));
    players.push_back(new Player(98734, "Paulson", "Marsha"));
    players.push_back(new Player(14998, "Quark", "John"));
    players.push_back(new Player(47303, "Rogers", "Jena"));
}

Team_3::Team_3() : Team("TEAM 3")
{
    players[46841] = new Player(46841, "Smith", "Ken");
    players[98765] = new Player(98765, "Terrance", "Laura");
    players[10547] = new Player(10547, "Ulster", "Doug");
    players[38331] = new Player(38331, "Vicks", "Ron");
    players[47781] = new Player(47781, "Wong", "Henrietta");
    players[57974] = new Player(61472, "Xavier", "Nancy");
    players[56712] = new Player(56712, "Yonnick", "Billy");
    players[72288] = new Player(72288, "Zachs", "Robby");
    players[40067] = new Player(40067, "Aaron", "Patricia");
}

enum PizzaType
{
    Regina = 1 ,
    Margarita = 2 ,
    Americana = 4 ,
    Fantasia = 8
};
enum PizzaSize
{
    S = 1 ,
    M = 2 ,
    L = 4 ,
    XL = 8 ,
    XXL = 16
};

// les ingredients : 

// ✓ Margarita: Contains dough, tomato and gruyere. Baked in 1 sec * multiplier.
// ✓ Regina: Contains dough, tomato, gruyere, ham, mushrooms. Baked in 2 secs * multiplier.
// ✓ Americana: Contains dough, tomato, gruyere, steak. Baked in 2 secs * multiplier.
// ✓ Fantasia: Contains dough, tomato, eggplant, goat cheese and chief love. Baked in 4 secs * multiplier.

// on doit verouiller les pizza qui passe et si
//  on ne peu pas car deja une dans le next et une en court
// alors on ne prends meme pas la pene de la lock et on la laisse
//et avant de donner des pizza on verifie si les cuisines ont assez d'ingredients pour les faires sinon on 
// la donne à une autre cuisine
// et si on la unlock car trop de pizza alors on verifie avant de
// simplement skip si il y a d'autres pizza dispo avec une barrier qui 
// va recuperer donc les nombres de cuisine qui a et si toutes disent non
// donc renvoie un pos a la barrier, alors elle fork une nouvelle cuisine qui
// pourra donc la lock


// faire aussi un managfer pour chaque cuisine qui va verifier si les 3 cuisinier
// ont leur pizza et si non en donner au autres

// aussi verifier le nombre de cuisine et le nombre de pizza et decouper la quantité equitablement entre
// chaque cuisine et mettre au max 2 pizza par cuisinier et si il y en a trop, fork le ombres de cuisine necessaire

// faire un timer de 5 secs a chaque debut de verification pour 
// voir si une pizza est pise et si oui alors on stop le timer
// et a la fin on regarde si le timer aest a plus de 5 secs
// avant toujours la verif du mutex lock

// faire des threads pour que lorsque le gas fait la commande il 
// envoie a tt les cook la commande et qu'elle se fait lock 
// des que une l'a recup

// dans le code aussi de chaque cook, pendant son code on va mettre un 
// timer qui va check si le temps recup au debut est passé et donc on recup tous
// les ingrédients et si plus d'ingrédient pour prendre des pizza, supp la cuisine et en recree une autre

// si la pizza est faite, faire parler un server qui dit que la pizza est prête à etre deguster 

//  une class pour le user et les getline des infos qu'il nous donne, 
// une class ou thread pour le manager qui va regarder si les cuisine on les disponibilité et qui va recuperer les pizza a faire et les donner au cuisiniers , ainsi que donner le temps de cuisson, et qui va regarder si il y a trop de pizza et recree le nombre de cuisine qu'on  a besoin par exemple si on a 10 pizza et que l'on a que 1 cuisinier par cuisine il faut en refaire 5 (5*1 cuisinier et 5*2 car 2 pizza par cuisinier)
// la class cuisine ou il va y avoir un nombre de cuisinier , un nombre d'ingredient, ensuoite un thread de cuisinier qui va regarder a chaque fois dans la class de la cuisine si les ingredients sont dispo et qui va recuperer du manager, le nom, ingredient et temps de cuisson de la pizza, et qui va une fois avoir fini la pizza, print "serveur: la pizza (pizza faite) est prete",
// et une fois le texte print se remettre en disponible pour refaire une autre pizza en next et prendre celle qui etait en next et la mettre en current et la faire
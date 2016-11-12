#include "ItemBuilder.h"

#include "ItemContainer.h"
#include "Item.h"
#include "Enhancement.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string get_iTname(int iit)
{
    string str;
    switch (iit)
    {
        case 1:
            str = "HELMET";
            break;
            
        case 2:
            str = "ARMOR";
            break;
            
        case 3:
            str = "SHIELD";
            break;
            
        case 4:
            str = "RING";
            break;
            
        case 5:
            str = "BELT";
            break;
            
        case 6:
            str = "BOOTS";
            break;
            
        case 7:
            str = "WEAPON";
            break;
            
        default:
            break;
    }
    return str;
}

//return name of enhancement
string get_eTname(int eet)
{
    string str;
    switch (eet)
    {
        case 1:
            str = "STRENTH";
            break;
            
        case 2:
            str = "DEXTERITY";
            break;
            
        case 3:
            str = "CONSTITUTION";
            break;
            
        case 4:
            str = "INTELLIGENCE";
            break;
            
        case 5:
            str = "WISDOM";
            break;
            
        case 6:
            str = "CHARISMA";
            break;
            
        case 7:
            str = "ARMOR_CLASS";
            break;
            
        case 8:
            str = "ATTACK_BONUS";
            break;
            
        case 9:
            str = "DAMAGE_BONUS";
            break;
            
        default:
            break;
    }
    return str;
}

//return name of container type
string get_cTname(int cct)
{
    string str;
    switch (cct)
    {
        case 1:
            str = "BACKPACK";
            break;
            
        case 2:
            str = "WORN_ITEMS";
            break;
            
        case 3:
            str = "CHEST";
            break;
            
        default:
            break;
    }
    return str;
}

//return container type
cType get_ctype(int c_type)
{
    cType ct;
    
    switch (c_type)
    {
        case 1:
            ct = BACKPACK;
            break;
        case 2:
            ct = WORN_ITEMS;
            break;
        case 3:
            ct = CHEST;
            break;
        default:
            break;
    }
    return ct;
}

//return item type
iType get_itype(int itype)
{
    iType it;
    switch (itype)
    {
        case 1:
            it = HELMET;
            break;
        case 2:
            it = ARMOR;
            break;
        case 3:
            it = SHIELD;
            break;
        case 4:
            it = RING;
            break;
        case 5:
            it = BELT;
            break;
        case 6:
            it = BOOTS;
            break;
        case 7:
            it = WEAPON;
            break;
        default:
            break;
    }
    return it;
}

//return enhancement type
eType get_etype(int etype)
{
    eType et;
    switch (etype)
    {
        case 1:
            et = STRENGTH;
            break;
        case 2:
            et = DEXTERITY;
            break;
        case 3:
            et = CONSTITUTION;
            break;
        case 4:
            et = INTELLIGENCE;
            break;
        case 5:
            et = WISDOM;
            break;
        case 6:
            et = CHARISMA;
            break;
        case 7:
            et = ARMOR_CLASS;
            break;
        case 8:
            et = ATTACK_BONUS;
            break;
        case 9:
            et = DAMAGE_BONUS;
            break;
        default:
            break;
    }
    return et;
}

//enter bonus value
int enterBonus()
{
    
    int b;
    
    do
    {
        cout << "\nPlease enter a <Value> (from 1 to 5) for the Enhancement:" << endl;
        cin >> b;
    } while (b < 1 || b > 5);
    
    return b;
}

//create a vector of enhancements
vector<Enhancement> createEnhancements(int i_opt)
{
    char ans;
    eType e_type;
    int e_option, bonus, counter = 0;
    Enhancement* influence;
    vector<Enhancement> influences;
    
    
    cout << "\nAdd an <Enhancement(s)> to this Item" << endl;
    
    switch (i_opt)
    {
        case 1:
            do
            {
                do
                {
                    cout << "\nPlease select an <Enhancement Type>: (<HELMET> CAN ONLY CONTAIN 3 ENHANCEMENTS)" << endl;
                    cout << "<1> INTELLIGENCE" << endl;
                    cout << "<2> WISDOM" << endl;
                    cout << "<3> ARMOR" << endl;
                    cin >> e_option;
                } while (e_option < 1 || e_option > 3);
                
                switch (e_option)
                {
                    case 1:
                        e_type = INTELLIGENCE;
                        bonus = enterBonus();
                        influence = new Enhancement(e_type, bonus);
                        influences.push_back(*influence);
                        break;
                        
                    case 2:
                        e_type = WISDOM;
                        bonus = enterBonus();
                        influence = new Enhancement(e_type, bonus);
                        influences.push_back(*influence);
                        break;
                        
                    case 3:
                        e_type = ARMOR_CLASS;
                        bonus = enterBonus();
                        influence = new Enhancement(e_type, bonus);
                        influences.push_back(*influence);
                        break;
                        
                    default:
                        break;
                }
                
                counter += 1;
                
                do
                {
                    if (counter >= 3)
                        ans = 'n';
                    else
                    {
                        cout << "\nAdd another <Enhancement>? (y / n)" << endl;
                        cin >> ans;
                    }
                } while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');
                
            } while ((ans == 'y' || ans == 'Y') && counter < 3);
            break;
            
        case 2:
            do
            {
                do
                {
                    cout << "\nPlease select an <Enhancement Type>: (<ARMOR> CAN ONLY CONTAIN 1 ENHANCEMENT1)" << endl;
                    cout << "<1> ARMOR_CLASS" << endl;
                    
                    cin >> e_option;
                } while (e_option != 1);
                
                switch (e_option)
                {
                    case 1:
                        e_type = ARMOR_CLASS;
                        bonus = enterBonus();
                        influence = new Enhancement(e_type, bonus);
                        influences.push_back(*influence);
                        break;
                        
                    default:
                        break;
                }
                
                counter += 1;
                
                do
                {
                    if (counter >= 1)
                        ans = 'n';
                    else
                    {
                        cout << "\nAdd another <Enhancement>? (y / n)" << endl;
                        cin >> ans;
                    }
                } while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');
                
            } while ((ans == 'y' || ans == 'Y') && counter < 1);
            break;
            
        case 3:
            do
            {
                do
                {
                    cout << "\nPlease select an <Enhancement Type>: (SHIELD CAN ONLY CONTAIN 1 ENHANCEMENT)" << endl;
                    cout << "<1> ARMOR_CLASS" << endl;
                    
                    cin >> e_option;
                } while (e_option != 1);
                
                switch (e_option)
                {
                    case 1:
                        e_type = ARMOR_CLASS;
                        bonus = enterBonus();
                        influence = new Enhancement(e_type, bonus);
                        influences.push_back(*influence);
                        break;
                        
                    default:
                        break;
                }
                
                counter += 1;
                
                do
                {
                    if (counter >= 1)
                        ans = 'n';
                    else
                    {
                        cout << "\nAdd another <Enhancement>? (y / n)" << endl;
                        cin >> ans;
                    }
                    
                } while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');
                
            } while ((ans == 'y' || ans == 'Y') && counter < 1);
            break;
            
        case 4:
            do
            {
                do
                {
                    cout << "\nPlease select an <Enhancement Type>: (<RING> CAN ONLY CONTAIN 5 ENHANCEMENTS)" << endl;
                    cout << "<1> ARMOR_CLASS" << endl;
                    cout << "<2> STRENGTH" << endl;
                    cout << "<3> CONSTITUTION" << endl;
                    cout << "<4> WISDOM" << endl;
                    cout << "<5> CHARISMA" << endl;
                    cin >> e_option;
                    
                } while (e_option < 1 || e_option > 5);
                
                switch (e_option)
                {
                    case 1:
                        e_type = ARMOR_CLASS;
                        bonus = enterBonus();
                        influence = new Enhancement(e_type, bonus);
                        influences.push_back(*influence);
                        break;
                        
                    case 2:
                        e_type = STRENGTH;
                        bonus = enterBonus();
                        influence = new Enhancement(e_type, bonus);
                        influences.push_back(*influence);
                        break;
                        
                    case 3:
                        e_type = CONSTITUTION;
                        bonus = enterBonus();
                        influence = new Enhancement(e_type, bonus);
                        influences.push_back(*influence);
                        break;
                        
                    case 4:
                        e_type = WISDOM;
                        bonus = enterBonus();
                        influence = new Enhancement(e_type, bonus);
                        influences.push_back(*influence);
                        break;
                        
                    case 5:
                        e_type = CHARISMA;
                        bonus = enterBonus();
                        influence = new Enhancement(e_type, bonus);
                        influences.push_back(*influence);
                        break;
                        
                    default:
                        break;
                }
                
                counter += 1;
                
                do
                {
                    if (counter >= 5)
                        ans = 'n';
                    else
                    {
                        cout << "\nAdd another <Enhancement>? (y / n)" << endl;
                        cin >> ans;
                    }
                    
                } while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');
                
            } while ((ans == 'y' || ans == 'Y') && counter < 5);
            break;
            
        case 5:
            do
            {
                do
                {
                    cout << "\nPlease select an <Enhancement Type>: (<BELT> CAN ONLY CONTAIN 2 ENHANCEMENTS)" << endl;
                    cout << "<1> CONSTITUTION" << endl;
                    cout << "<2> STRENGTH" << endl;
                    cin >> e_option;
                    
                } while (e_option < 1 || e_option > 2);
                
                switch (e_option)
                {
                    case 1:
                        e_type = CONSTITUTION;
                        bonus = enterBonus();
                        influence = new Enhancement(e_type, bonus);
                        influences.push_back(*influence);
                        break;
                        
                    case 2:
                        e_type = STRENGTH;
                        bonus = enterBonus();
                        influence = new Enhancement(e_type, bonus);
                        influences.push_back(*influence);
                        break;
                        
                    default:
                        break;
                }
                
                counter += 1;
                
                do
                {
                    if (counter >= 2)
                        ans = 'n';
                    else
                    {
                        cout << "\nAdd another <Enhancement>? (y / n)" << endl;
                        cin >> ans;
                    }
                    
                } while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');
                
            } while ((ans == 'y' || ans == 'Y') && counter < 2);
            break;
            
        case 6:
            do
            {
                do
                {
                    cout << "\nPlease select an <Enhancement Type>: (<BOOTS> CAN ONLY CONTAIN 2 ENHANCEMENTS)" << endl;
                    cout << "<1> ARMOR_CLASS" << endl;
                    cout << "<2> DEXTERITY" << endl;
                    cin >> e_option;
                    
                } while (e_option < 1 || e_option > 2);
                
                switch (e_option)
                {
                    case 1:
                        e_type = ARMOR_CLASS;
                        bonus = enterBonus();
                        influence = new Enhancement(e_type, bonus);
                        influences.push_back(*influence);
                        break;
                        
                    case 2:
                        e_type = DEXTERITY;
                        bonus = enterBonus();
                        influence = new Enhancement(e_type, bonus);
                        influences.push_back(*influence);
                        break;
                        
                    default:
                        break;
                }
                
                counter += 1;
                
                do
                {
                    if (counter >= 2)
                        ans = 'n';
                    else
                    {
                        cout << "\nAdd another <Enhancement>? (y / n)" << endl;
                        cin >> ans;
                    }
                    
                } while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');
                
            } while ((ans == 'y' || ans == 'Y') && counter < 2);
            break;
            
        case 7:
            do
            {
                do
                {
                    cout << "\nPlease select an <Enhancement Type>: (<WEAPON> CAN ONLY CONTAIN 2 ENHANCEMENTS)" << endl;
                    cout << "<1> ATTACK_BONUS" << endl;
                    cout << "<2> DAMAGE_BONUS" << endl;
                    cin >> e_option;
                    
                } while (e_option < 1 || e_option > 2);
                
                switch (e_option)
                {
                    case 1:
                        e_type = ATTACK_BONUS;
                        bonus = enterBonus();
                        influence = new Enhancement(e_type, bonus);
                        influences.push_back(*influence);
                        break;
                        
                    case 2:
                        e_type = DAMAGE_BONUS;
                        bonus = enterBonus();
                        influence = new Enhancement(e_type, bonus);
                        influences.push_back(*influence);
                        break;
                        
                    default:
                        break;
                }
                
                counter += 1;
                
                do
                {
                    if (counter >= 2)
                        ans = 'n';
                    else
                    {
                        cout << "\nAdd another <Enhancement>? (y / n)" << endl;
                        cin >> ans;
                    }
                    
                } while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');
                
            } while ((ans == 'y' || ans == 'Y') && counter < 2);
            break;
    }
    
    return influences;
}

//save an item
void saveI(string fileName, Item item)
{
    
    ofstream outf;
    outf.open("resources/save_items/"+fileName);
    
    outf << item.getName() << endl;
    outf << item.getType() << endl;
    
    for (int i = 0; i < item.getEnhances().size(); i++)
    {
        outf << item.getEnhances()[i].getType() << " " << item.getEnhances()[i].getBonus() << endl;
    }
    
    outf << ";";
    
    outf.close();
    
    cout << "Saving..." << endl << endl;
}

//create an item
void createItem1()
{
    
    int f_ictr = 1;
    string istr, fn;
    char ans;
    string i_name;
    iType i_type;
    int i_option, iitype, eetype;
    vector<Enhancement> enhances;
    Item* item;
    
    
    
    do
    {
        do
        {
            cout << "\nCreate an <Item>" << endl;
            cout << "Please select an <Item Type> :" << endl;
            cout << "<1> HELMET" << endl;
            cout << "<2> ARMOR" << endl;
            cout << "<3> SHIELD" << endl;
            cout << "<4> RING" << endl;
            cout << "<5> BELT" << endl;
            cout << "<6> BOOTS" << endl;
            cout << "<7> WEAPON" << endl;
            cout << "<0> EXIT" << endl;
            cin >> i_option;
        } while (i_option < 0 || i_option > 7);
        
        switch (i_option)
        {
            case 1:
                i_type = HELMET;
                enhances = createEnhancements(i_option);
                break;
                
            case 2:
                i_type = ARMOR;
                enhances = createEnhancements(i_option);
                break;
                
            case 3:
                i_type = SHIELD;
                enhances = createEnhancements(i_option);
                break;
                
            case 4:
                i_type = RING;
                enhances = createEnhancements(i_option);
                break;
                
            case 5:
                i_type = BELT;
                enhances = createEnhancements(i_option);
                break;
                
            case 6:
                i_type = BOOTS;
                enhances = createEnhancements(i_option);
                break;
                
            case 7:
                i_type = WEAPON;
                enhances = createEnhancements(i_option);
                break;
                
            case -1:
                break;
                
            default:
                break;
        }
        
        cout << "\nPlease enter a <Name> for the Item:" << endl;
        cin >> i_name;
        
        item = new Item(i_name, i_type, enhances);
        istr = to_string(f_ictr);
        fn = "item" + istr + ".txt";
        saveI(fn, *item);
        
        cout << "\n" << item->getName() << endl;
        
        iitype = item->getType();
        cout << get_iTname(iitype) << endl;
        for (int i = 0; i < item->getEnhances().size(); i++)
        {
            eetype = item->getEnhances()[i].getType();
            cout << "[" << i << "] " << get_eTname(eetype) << ": " << item->getEnhances()[i].getBonus() << endl;
        }
        
        
        do
        {
            cout << "\nCreate or Add another <Item>? (y or n)" << endl;
            cin >> ans;
        } while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');
        
        f_ictr += 1;
        
    } while (ans == 'y' || ans == 'Y');
    
    
    
}

//create a vector of items for itemcontainer
vector<Item> createItem2()
{
    char ans;
    string i_name;
    iType i_type;
    int i_option;
    vector<Enhancement> enhances;
    Item* item;
    vector<Item> items;
    
    
    do
    {
        do
        {
            cout << "\nCreate an <Item>" << endl;
            cout << "Please select an <Item Type> :" << endl;
            cout << "<1> HELMET" << endl;
            cout << "<2> ARMOR" << endl;
            cout << "<3> SHIELD" << endl;
            cout << "<4> RING" << endl;
            cout << "<5> BELT" << endl;
            cout << "<6> BOOTS" << endl;
            cout << "<7> WEAPON" << endl;
            cout << "<0> EXIT" << endl;
            cin >> i_option;
        } while (i_option < 0 || i_option > 7);
        
        switch (i_option)
        {
            case 1:
                i_type = HELMET;
                enhances = createEnhancements(i_option);
                break;
                
            case 2:
                i_type = ARMOR;
                enhances = createEnhancements(i_option);
                break;
                
            case 3:
                i_type = SHIELD;
                enhances = createEnhancements(i_option);
                break;
                
            case 4:
                i_type = RING;
                enhances = createEnhancements(i_option);
                break;
                
            case 5:
                i_type = BELT;
                enhances = createEnhancements(i_option);
                break;
                
            case 6:
                i_type = BOOTS;
                enhances = createEnhancements(i_option);
                break;
                
            case 7:
                i_type = WEAPON;
                enhances = createEnhancements(i_option);
                break;
                
            case -1:
                break;
                
            default:
                break;
        }
        
        cout << "\nPlease enter a <Name> for the Item:" << endl;
        cin >> i_name;
        
        item = new Item(i_name, i_type, enhances);
        items.push_back(*item);
        
        do
        {
            cout << "\nCreate or Add another <Item>? (y or n)" << endl;
            cin >> ans;
        } while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');
        
    } while (ans == 'y' || ans == 'Y');
    
    return items;
    
}

//create worn items
vector<Item> createItem3()
{
    
    char ans;
    string i_name;
    iType i_type;
    int i_option;
    vector<Enhancement> enhances;
    Item* item;
    vector<Item> items;
    
    
    
    cout << "\nThis Item Container is for Character Worn Items, therefore items will be created in following order" << endl;
    
    cout << "\n<1> Create a HELMET" << endl;
    i_type = HELMET;
    enhances = createEnhancements(1);
    cout << "\nPlease enter a <Name> for the Item:" << endl;
    cin >> i_name;
    item = new Item(i_name, i_type, enhances);
    items.push_back(*item);
    
    cout << "\n<2> Create an ARMOR" << endl;
    i_type = ARMOR;
    enhances = createEnhancements(2);
    cout << "\nPlease enter a <Name> for the Item:" << endl;
    cin >> i_name;
    item = new Item(i_name, i_type, enhances);
    items.push_back(*item);
    
    cout << "\n<3> Create a SHIELD" << endl;
    i_type = SHIELD;
    enhances = createEnhancements(3);
    cout << "\nPlease enter a <Name> for the Item:" << endl;
    cin >> i_name;
    item = new Item(i_name, i_type, enhances);
    items.push_back(*item);
    
    cout << "\n<4> Create a RING" << endl;
    i_type = RING;
    enhances = createEnhancements(4);
    cout << "\nPlease enter a <Name> for the Item:" << endl;
    cin >> i_name;
    item = new Item(i_name, i_type, enhances);
    items.push_back(*item);
    
    cout << "\n<5> Create a BELT" << endl;
    i_type = BELT;
    enhances = createEnhancements(5);
    cout << "\nPlease enter a <Name> for the Item:" << endl;
    cin >> i_name;
    item = new Item(i_name, i_type, enhances);
    items.push_back(*item);
    
    cout << "\n<6> Create a BOOTS" << endl;
    i_type = BOOTS;
    enhances = createEnhancements(6);
    cout << "\nPlease enter a <Name> for the Item:" << endl;
    cin >> i_name;
    item = new Item(i_name, i_type, enhances);
    items.push_back(*item);
    
    cout << "\n<7> Create a WEAPON" << endl;
    i_type = WEAPON;
    enhances = createEnhancements(7);
    cout << "\nPlease enter a <Name> for the Item:" << endl;
    cin >> i_name;
    item = new Item(i_name, i_type, enhances);
    items.push_back(*item);
    
    return items;
    
}

//save an Item Container
void saveIC(string fileName, ItemContainer ic)
{
    
    ofstream outf;
    outf.open("resources/save_container/"+fileName);
    
    outf << ic.getType() << endl;
    
    
    for (int i = 0; i < ic.getItems().size(); i++)
    {
        outf << ic.getItems()[i].getName() << endl;
        outf << ic.getItems()[i].getType() << endl;
        
        for (int j = 0; j < ic.getItems()[i].getEnhances().size(); j++)
        {
            outf << ic.getItems()[i].getEnhances()[j].getType() << " " << ic.getItems()[i].getEnhances()[j].getBonus() << endl;
        }
        outf << ";" << endl;
    }
    
    outf.close();
    
    cout << "Saving..." << endl << endl;
}

//create an Item Container
void createItemContainer()
{
    
    int f_cctr = 1;
    string fn, cstr;
    char ans;
    int c_option, cctype, iitype, eetype;
    cType c_t;
    ItemContainer* ic;
    vector<Item>* items;
    
    do
    {
        
        do
        {
            cout << "\nCreate an <Item Conatiner>" << endl;
            cout << "Please select an <Item Container Type>:" << endl;
            cout << "<1> CHARACTER BACKPACK" << endl;
            cout << "<2> CHARATER INVENTORY PANE (FOR WORN ITEMS)" << endl;
            cout << "<3> TREASURE CHEST" << endl;
            cout << "<0> EXIT" << endl;
            cin >> c_option;
        } while (c_option < 0 || c_option > 3);
        
        switch (c_option)
        {
                
            case 1:
                c_t = BACKPACK;
                items = new vector<Item>(createItem2());
                ic = new ItemContainer(c_t, *items);
                cstr = to_string(f_cctr);
                fn = "backpack.txt";
                saveIC(fn, *ic);
                
                cctype = ic->getType();
                cout << "\n" << get_cTname(cctype) << endl;
                
                for (int i = 0; i < ic->getItems().size(); i++)
                {
                    cout << ic->getItems()[i].getName() << endl;
                    iitype = ic->getItems()[i].getType();
                    cout << "[" << i << "] " << get_iTname(iitype) << endl;
                    for (int j = 0; j < ic->getItems()[i].getEnhances().size(); j++)
                    {
                        eetype = ic->getItems()[i].getEnhances()[j].getType();
                        cout << "[" << j << "] " << get_eTname(eetype) << ": " << ic->getItems()[i].getEnhances()[j].getBonus() << endl;
                    }
                }
                
                break;
                
            case 2:
                c_t = WORN_ITEMS;
                items = new vector<Item>(createItem3());
                ic = new ItemContainer(c_t, *items);
                cstr = to_string(f_cctr);
                fn = "worn.txt";
                saveIC(fn, *ic);
                
                cctype = ic->getType();
                cout << "\n" << get_cTname(cctype) << endl;
                
                for (int i = 0; i < ic->getItems().size(); i++)
                {
                    cout << ic->getItems()[i].getName() << endl;
                    iitype = ic->getItems()[i].getType();
                    cout << "[" << i << "] " << get_iTname(iitype) << endl;
                    for (int j = 0; j < ic->getItems()[i].getEnhances().size(); j++)
                    {
                        eetype = ic->getItems()[i].getEnhances()[j].getType();
                        cout << "[" << j << "] " << get_eTname(eetype) << ": " << ic->getItems()[i].getEnhances()[j].getBonus() << endl;
                    }
                }
                break;
                
            case 3:
                c_t = CHEST;
                items = new vector<Item>(createItem2());
                ic = new ItemContainer(c_t, *items);
                cstr = to_string(f_cctr);
                fn = "chest" + cstr + ".txt";
                saveIC(fn, *ic);
                
                cctype = ic->getType();
                cout << "\n" << get_cTname(cctype) << endl;
                
                for (int i = 0; i < ic->getItems().size(); i++)
                {
                    cout << ic->getItems()[i].getName() << endl;
                    iitype = ic->getItems()[i].getType();
                    cout << "[" << i << "] " << get_iTname(iitype) << endl;
                    for (int j = 0; j < ic->getItems()[i].getEnhances().size(); j++)
                    {
                        eetype = ic->getItems()[i].getEnhances()[j].getType();
                        cout << "[" << j << "] " << get_eTname(eetype) << ": " << ic->getItems()[i].getEnhances()[j].getBonus() << endl;
                    }
                }
                f_cctr += 1;
                
                break;
                
            case -1:
                break;
                
            default:
                break;
        }
        
        
        do
        {
            cout << "\nCreate another <Item Container>? (y or n)" << endl;
            cin >> ans;
        } while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');
        
        //f_cctr += 1;
        
    } while (ans == 'y' || ans == 'Y');
    
}

//load an Item
void loadItem(string f_name, Item& item)
{
    string i_name;
    int i_type, e_type, e_bonus;
    Enhancement enhance;
    vector<Enhancement> v_enhances;
    
    ifstream inf;
    inf.open("resources/save_items/"+f_name);
    
    getline(inf, i_name);
    item.setName(i_name);
    
    inf >> i_type;
    item.setType(get_itype(i_type));
    
    
    
    while (!(inf.peek() == ';'))
    {
        inf >> e_type;
        enhance.setType(get_etype(e_type));
        inf >> e_bonus;
        enhance.setBonus(e_bonus);
        v_enhances.push_back(enhance);
        getline(inf, i_name);
        
    }
    
    item.setEnhances(v_enhances);
    
    inf.close();
    
}


//Load an Item Container
void loadItemContainer(string f_name, ItemContainer& ic)
{
    
    
    int c_type;
    string i_name;
    int i_type, e_type, e_bonus;
    
    Item item;
    vector<Item> v_items;
    Enhancement enhance;
    vector<Enhancement> v_enhances;
    
    ifstream inf;
    inf.open("resources/save_container/"+f_name);
    
    inf >> c_type;
    ic.setType(get_ctype(c_type));
    getline(inf, i_name);
    
    while (!(inf.eof()))
    {
        getline(inf, i_name);
        if (i_name == "")
            break;
        item.setName(i_name);
        
        inf >> i_type;
        item.setType(get_itype(i_type));
        getline(inf, i_name);
        
        while (!(inf.peek() == ';'))
        {
            inf >> e_type;
            enhance.setType(get_etype(e_type));
            inf >> e_bonus;
            enhance.setBonus(e_bonus);
            v_enhances.push_back(enhance);
            getline(inf, i_name);
            
        }
        
        item.setEnhances(v_enhances);
        v_items.push_back(item);
        v_enhances.clear();
        
        getline(inf, i_name);
        
    }
    
    ic.setItems(v_items);
    
    inf.close();
    
}

//edit an item
void editItem(string f_name, Item &m_item)
{
    char ans1, ans2, ans3;
    int sel1, sel2, sel3, sel4, itt, ett;
    string newName;
    eType e_type;
    int bonus, counter = 0;
    Enhancement* influence;
    vector<Enhancement> influences;
    
    do
    {
        do
        {
            cout << "\nPlease select the option you wish to edit?" << endl;
            cout << "<1> <Name> of the item" << endl;
            cout << "<2> <Type> of the item" << endl;
            cout << "<3> <Enhancement(s)> of the item" << endl;
            cout << "<0> Cancel" << endl;
            cin >> sel1;
        } while (sel1 < 0 || sel1 > 3);
        
        switch (sel1)
        {
            case 1:
                cout << "\nEnter the new <Name>:" << endl;
                cin >> newName;
                m_item.setName(newName);
                break;
                
            case 2:
                cout << "\nSelect the new <Type>: (NOTE: chaning the <Type> will force you to enter the new <Enhancements>)" << endl;
                cout << "<1> HELMET" << endl;
                cout << "<2> ARMOR" << endl;
                cout << "<3> SHIELD" << endl;
                cout << "<4> RING" << endl;
                cout << "<5> BELT" << endl;
                cout << "<6> BOOTS" << endl;
                cout << "<7> WEAPON" << endl;
                cin >> sel2;
                
                switch (sel2)
            {
                case 1:
                    m_item.setType(get_itype(sel2));
                    
                    do
                    {
                        do
                        {
                            cout << "\nPlease select an <Enhancement Type>: (<HELMET> CAN ONLY CONTAIN 3 ENHANCEMENTS)" << endl;
                            cout << "<1> INTELLIGENCE" << endl;
                            cout << "<2> WISDOM" << endl;
                            cout << "<3> ARMOR" << endl;
                            cin >> sel3;
                        } while (sel3 < 1 || sel3 > 3);
                        
                        switch (sel3)
                        {
                            case 1:
                                e_type = INTELLIGENCE;
                                bonus = enterBonus();
                                influence = new Enhancement(e_type, bonus);
                                influences.push_back(*influence);
                                break;
                                
                            case 2:
                                e_type = WISDOM;
                                bonus = enterBonus();
                                influence = new Enhancement(e_type, bonus);
                                influences.push_back(*influence);
                                break;
                                
                            case 3:
                                e_type = ARMOR_CLASS;
                                bonus = enterBonus();
                                influence = new Enhancement(e_type, bonus);
                                influences.push_back(*influence);
                                break;
                                
                            default:
                                break;
                        }
                        
                        counter += 1;
                        
                        do
                        {
                            if (counter >= 3)
                                ans2 = 'n';
                            else
                            {
                                cout << "\nAdd another <Enhancement>? (y / n)" << endl;
                                cin >> ans2;
                            }
                        } while (ans2 != 'y' && ans2 != 'Y' && ans2 != 'n' && ans2 != 'N');
                        
                    } while ((ans2 == 'y' || ans2 == 'Y') && counter < 3);
                    
                    m_item.setEnhances(influences);
                    break;
                    
                case 2:
                    m_item.setType(get_itype(sel2));
                    
                    do
                    {
                        do
                        {
                            cout << "\nPlease select an <Enhancement Type>: (<ARMOR> CAN ONLY CONTAIN 1 ENHANCEMENT1)" << endl;
                            cout << "<1> ARMOR_CLASS" << endl;
                            
                            cin >> sel3;
                        } while (sel3 != 1);
                        
                        switch (sel3)
                        {
                            case 1:
                                e_type = ARMOR_CLASS;
                                bonus = enterBonus();
                                influence = new Enhancement(e_type, bonus);
                                influences.push_back(*influence);
                                break;
                                
                            default:
                                break;
                        }
                        
                        counter += 1;
                        
                        do
                        {
                            if (counter >= 1)
                                ans2 = 'n';
                            else
                            {
                                cout << "\nAdd another <Enhancement>? (y / n)" << endl;
                                cin >> ans2;
                            }
                        } while (ans2 != 'y' && ans2 != 'Y' && ans2 != 'n' && ans2 != 'N');
                        
                    } while ((ans2 == 'y' || ans2 == 'Y') && counter < 1);
                    
                    m_item.setEnhances(influences);
                    break;
                    
                case 3:
                    m_item.setType(get_itype(sel2));
                    
                    do
                    {
                        do
                        {
                            cout << "\nPlease select an <Enhancement Type>: (SHIELD CAN ONLY CONTAIN 1 ENHANCEMENT)" << endl;
                            cout << "<1> ARMOR_CLASS" << endl;
                            
                            cin >> sel3;
                        } while (sel3 != 1);
                        
                        switch (sel3)
                        {
                            case 1:
                                e_type = ARMOR_CLASS;
                                bonus = enterBonus();
                                influence = new Enhancement(e_type, bonus);
                                influences.push_back(*influence);
                                break;
                                
                            default:
                                break;
                        }
                        
                        counter += 1;
                        
                        do
                        {
                            if (counter >= 1)
                                ans2 = 'n';
                            else
                            {
                                cout << "\nAdd another <Enhancement>? (y / n)" << endl;
                                cin >> ans2;
                            }
                            
                        } while (ans2 != 'y' && ans2 != 'Y' && ans2 != 'n' && ans2 != 'N');
                        
                    } while ((ans2 == 'y' || ans2 == 'Y') && counter < 1);
                    
                    m_item.setEnhances(influences);
                    break;
                    
                case 4:
                    m_item.setType(get_itype(sel2));
                    
                    do
                    {
                        do
                        {
                            cout << "\nPlease select an <Enhancement Type>: (<RING> CAN ONLY CONTAIN 5 ENHANCEMENTS)" << endl;
                            cout << "<1> ARMOR_CLASS" << endl;
                            cout << "<2> STRENGTH" << endl;
                            cout << "<3> CONSTITUTION" << endl;
                            cout << "<4> WISDOM" << endl;
                            cout << "<5> CHARISMA" << endl;
                            cin >> sel3;
                            
                        } while (sel3 < 1 || sel3 > 5);
                        
                        switch (sel3)
                        {
                            case 1:
                                e_type = ARMOR_CLASS;
                                bonus = enterBonus();
                                influence = new Enhancement(e_type, bonus);
                                influences.push_back(*influence);
                                break;
                                
                            case 2:
                                e_type = STRENGTH;
                                bonus = enterBonus();
                                influence = new Enhancement(e_type, bonus);
                                influences.push_back(*influence);
                                break;
                                
                            case 3:
                                e_type = CONSTITUTION;
                                bonus = enterBonus();
                                influence = new Enhancement(e_type, bonus);
                                influences.push_back(*influence);
                                break;
                                
                            case 4:
                                e_type = WISDOM;
                                bonus = enterBonus();
                                influence = new Enhancement(e_type, bonus);
                                influences.push_back(*influence);
                                break;
                                
                            case 5:
                                e_type = CHARISMA;
                                bonus = enterBonus();
                                influence = new Enhancement(e_type, bonus);
                                influences.push_back(*influence);
                                break;
                                
                            default:
                                break;
                        }
                        
                        counter += 1;
                        
                        do
                        {
                            if (counter >= 5)
                                ans2 = 'n';
                            else
                            {
                                cout << "\nAdd another <Enhancement>? (y / n)" << endl;
                                cin >> ans2;
                            }
                            
                        } while (ans2 != 'y' && ans2 != 'Y' && ans2 != 'n' && ans2 != 'N');
                        
                    } while ((ans2 == 'y' || ans2 == 'Y') && counter < 5);
                    
                    m_item.setEnhances(influences);
                    break;
                    
                case 5:
                    m_item.setType(get_itype(sel2));
                    
                    do
                    {
                        do
                        {
                            cout << "\nPlease select an <Enhancement Type>: (<BELT> CAN ONLY CONTAIN 2 ENHANCEMENTS)" << endl;
                            cout << "<1> CONSTITUTION" << endl;
                            cout << "<2> STRENGTH" << endl;
                            cin >> sel3;
                            
                        } while (sel3 < 1 || sel3 > 2);
                        
                        switch (sel3)
                        {
                            case 1:
                                e_type = CONSTITUTION;
                                bonus = enterBonus();
                                influence = new Enhancement(e_type, bonus);
                                influences.push_back(*influence);
                                break;
                                
                            case 2:
                                e_type = STRENGTH;
                                bonus = enterBonus();
                                influence = new Enhancement(e_type, bonus);
                                influences.push_back(*influence);
                                break;
                                
                            default:
                                break;
                        }
                        
                        counter += 1;
                        
                        do
                        {
                            if (counter >= 2)
                                ans2 = 'n';
                            else
                            {
                                cout << "\nAdd another <Enhancement>? (y / n)" << endl;
                                cin >> ans2;
                            }
                            
                        } while (ans2 != 'y' && ans2 != 'Y' && ans2 != 'n' && ans2 != 'N');
                        
                    } while ((ans2 == 'y' || ans2 == 'Y') && counter < 2);
                    
                    m_item.setEnhances(influences);
                    break;
                    
                case 6:
                    m_item.setType(get_itype(sel2));
                    
                    do
                    {
                        do
                        {
                            cout << "\nPlease select an <Enhancement Type>: (<BOOTS> CAN ONLY CONTAIN 2 ENHANCEMENTS)" << endl;
                            cout << "<1> ARMOR_CLASS" << endl;
                            cout << "<2> DEXTERITY" << endl;
                            cin >> sel3;
                            
                        } while (sel3 < 1 || sel3 > 2);
                        
                        switch (sel3)
                        {
                            case 1:
                                e_type = ARMOR_CLASS;
                                bonus = enterBonus();
                                influence = new Enhancement(e_type, bonus);
                                influences.push_back(*influence);
                                break;
                                
                            case 2:
                                e_type = DEXTERITY;
                                bonus = enterBonus();
                                influence = new Enhancement(e_type, bonus);
                                influences.push_back(*influence);
                                break;
                                
                            default:
                                break;
                        }
                        
                        counter += 1;
                        
                        do
                        {
                            if (counter >= 2)
                                ans2 = 'n';
                            else
                            {
                                cout << "\nAdd another <Enhancement>? (y / n)" << endl;
                                cin >> ans2;
                            }
                            
                        } while (ans2 != 'y' && ans2 != 'Y' && ans2 != 'n' && ans2 != 'N');
                        
                    } while ((ans2 == 'y' || ans2 == 'Y') && counter < 2);
                    
                    m_item.setEnhances(influences);
                    break;
                    
                case 7:
                    m_item.setType(get_itype(sel2));
                    
                    do
                    {
                        do
                        {
                            cout << "\nPlease select an <Enhancement Type>: (<WEAPON> CAN ONLY CONTAIN 2 ENHANCEMENTS)" << endl;
                            cout << "<1> ATTACK_BONUS" << endl;
                            cout << "<2> DAMAGE_BONUS" << endl;
                            cin >> sel3;
                            
                        } while (sel3 < 1 || sel3 > 2);
                        
                        switch (sel3)
                        {
                            case 1:
                                e_type = ATTACK_BONUS;
                                bonus = enterBonus();
                                influence = new Enhancement(e_type, bonus);
                                influences.push_back(*influence);
                                break;
                                
                            case 2:
                                e_type = DAMAGE_BONUS;
                                bonus = enterBonus();
                                influence = new Enhancement(e_type, bonus);
                                influences.push_back(*influence);
                                break;
                                
                            default:
                                break;
                        }
                        
                        counter += 1;
                        
                        do
                        {
                            if (counter >= 2)
                                ans2 = 'n';
                            else
                            {
                                cout << "\nAdd another <Enhancement>? (y / n)" << endl;
                                cin >> ans2;
                            }
                            
                        } while (ans2 != 'y' && ans2 != 'Y' && ans2 != 'n' && ans2 != 'N');
                        
                    } while ((ans2 == 'y' || ans2 == 'Y') && counter < 2);
                    
                    m_item.setEnhances(influences);
                    break;
                    
                default:
                    break;
            }
                break;
                
            case 3:
                do
                {
                    cout << m_item.getName() << endl;
                    
                    itt = m_item.getType();
                    cout << get_iTname(itt) << endl;
                    for (int i = 0; i < m_item.getEnhances().size(); i++)
                    {
                        ett = m_item.getEnhances()[i].getType();
                        cout << "[" << i << "] " << get_eTname(ett) << ": " << m_item.getEnhances()[i].getBonus() << endl;
                    }
                    
                    cout << "\nEnter the [Index] of the Enhancements you wish to change the value:" << endl;
                    cin >> sel4;
                    cout << "\nEnter the new Bonus value:" << endl;
                    cin >> bonus;
                    
                    influences.clear();
                    influences = m_item.getEnhances();
                    
                    influences[sel4].setBonus(bonus);
                    
                    m_item.setEnhances(influences);
                    
                    
                    do
                    {
                        cout << "\nEdit another Enchancement? (y or n)" << endl;
                        cin >> ans3;
                    } while (ans3 != 'y' && ans3 != 'Y' && ans3 != 'n' && ans3 != 'N');
                    
                } while (ans3 == 'y' || ans3 == 'Y');
                
                break;
                
            case 0:
                break;
                
            default:
                break;
        }
        
        do
        {
            cout << "\nEdit this Item again? (y or n)" << endl;
            cin >> ans1;
        } while (ans1 != 'y' && ans1 != 'Y' && ans1 != 'n' && ans1 != 'N');
        
        
        
        cout << "\n" << m_item.getName() << endl;
        
        itt = m_item.getType();
        cout << get_iTname(itt) << endl;
        for (int i = 0; i < m_item.getEnhances().size(); i++)
        {
            ett = m_item.getEnhances()[i].getType();
            cout << "[" << i << "] " << get_eTname(ett) << ": " << m_item.getEnhances()[i].getBonus() << endl;
        }
        
    } while (ans1 == 'y' || ans1 == 'Y');
    
}

//edit an item container
void editItemContainer(string f_name, ItemContainer &m_ic)
{
    char ans1;
    int sel1;
    Item* item;
    vector<Item> items;
    
    int iit, eet, cct;
    
    do
    {
        cout << "\nPlease select the item you wish to edit by selecting the <Index> of the specific item from above:" << endl;
        cin >> sel1;
        
        items = m_ic.getItems();
        
        editItem(f_name, items[sel1]);
        
        m_ic.setItems(items);
        
        do
        {
            cout << "\nEdit another item in this item container? (y or n)" << endl;
            cin >> ans1;
        } while (ans1 != 'y' && ans1 != 'Y' && ans1 != 'n' && ans1 != 'N');
        
        cct = m_ic.getType();
        cout << "\n" << get_cTname(cct) << endl;
        
        for (int i = 0; i < m_ic.getItems().size(); i++)
        {
            cout << "[" << i << "] " << m_ic.getItems()[i].getName() << endl;
            iit = m_ic.getItems()[i].getType();
            cout << get_iTname(iit) << endl;
            for (int j = 0; j < m_ic.getItems()[i].getEnhances().size(); j++)
            {
                eet = m_ic.getItems()[i].getEnhances()[j].getType();
                cout << get_eTname(eet) << ": " << m_ic.getItems()[i].getEnhances()[j].getBonus() << endl;
            }
        }
        
    } while (ans1 == 'y' || ans1 == 'Y');
    
    
}



int ItemMenu()
{
    
    char ans;
    int opt1, opt2;
    string input_fn;
    Item* item = new Item;
    ItemContainer* item_container = new ItemContainer;
    int iitype, eetype, cctype;
    
    do
    {
        do
        {
            cout << "\nPlease select an <Option>:" << endl;
            cout << "<1> Create an <Item>" << endl;
            cout << "<2> Create an <Item Container>" << endl;
            cout << "<3> Load an <Item>" << endl;
            cout << "<4> Load an <Item Container>" << endl;
            cout << "<0> Exit" << endl;
            cin >> opt1;
        } while (opt1 < 0 || opt1 > 4);
        
        switch (opt1)
        {
            case 1:
                createItem1();
                break;
                
            case 2:
                createItemContainer();
                break;
                
            case 3:
                cout << "\nPlease enter the <file name>:" << endl;
                cin >> input_fn;
                input_fn = input_fn + ".txt";
                loadItem(input_fn, *item);
                
                cout << "\n" << item->getName() << endl;
                
                iitype = item->getType();
                cout << get_iTname(iitype) << endl;
                for (int i = 0; i < item->getEnhances().size(); i++)
                {
                    eetype = item->getEnhances()[i].getType();
                    cout << "[" << i << "] " << get_eTname(eetype) << ": " << item->getEnhances()[i].getBonus() << endl;
                }
                
                cout << "\nWould you like to:" << endl;
                cout << "<1> Edit the <Item>" << endl;
                cout << "<0> Exit" << endl;
                cin >> opt2;
                
                switch (opt2)
            {
                case 1:
                    editItem(input_fn, *item);
                    saveI(input_fn, *item);
                    
                    break;
                    
                case 0:
                    break;
                    
                default:
                    break;
            }
                
                
                break;
                
            case 4:
                cout << "\nPlease enter the <file name>:" << endl;
                cin >> input_fn;
                input_fn = input_fn + ".txt";
                loadItemContainer(input_fn, *item_container);
                
                cctype = item_container->getType();
                cout << "\n" << get_cTname(cctype) << endl;
                
                for (int i = 0; i < item_container->getItems().size(); i++)
                {
                    cout << "[" << i << "] " << item_container->getItems()[i].getName() << endl;
                    iitype = item_container->getItems()[i].getType();
                    cout << get_iTname(iitype) << endl;
                    for (int j = 0; j < item_container->getItems()[i].getEnhances().size(); j++)
                    {
                        eetype = item_container->getItems()[i].getEnhances()[j].getType();
                        cout << get_eTname(eetype) << ": " << item_container->getItems()[i].getEnhances()[j].getBonus() << endl;
                    }
                }
                
                cout << "\nWould you like to:" << endl;
                cout << "<1> Edit the <Item(s)> in this Item Container" << endl;
                cout << "<0> Exit" << endl;
                cin >> opt2;
                
                switch (opt2)
            {
                case 1:
                    editItemContainer(input_fn, *item_container);
                    saveIC(input_fn, *item_container);
                    
                    break;
                    
                case 0:
                    break;
                    
                default:
                    break;
            }
                
                
                break;
                
            case 0:
                break;
                
            default:
                break;
        }
        
        if (opt1 == 0)
        {
            system("pause");
            return 0;
        }
        else
        {
            do
            {
                cout << "\nBakc to Main Menu? (y or n)" << endl;
                cin >> ans;
            } while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');
        }
        
    } while (ans == 'y' || ans == 'Y');
    
    
    system("pause");
    return 0;
}

void displayIC(ItemContainer &ic)
{
    int iitype;
    eType eetype;
    
    for (int i = 0; i < ic.getItems().size(); i++)
    {
        cout << "[" << i << "] " << ic.getItems()[i].getName() << endl;
        iitype = ic.getItems()[i].getType();
        cout << get_iTname(iitype) << endl;
        for (int j = 0; j < ic.getItems()[i].getEnhances().size(); j++)
        {
            eetype = ic.getItems()[i].getEnhances()[j].getType();
            
            
            cout << get_eTname(eetype) << ": " << ic.getItems()[i].getEnhances()[j].getBonus() << endl;
        }
    }
}

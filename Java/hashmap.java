import java.util.*;

public class Hashmap {
    public static void main(String[] args) {

//        CREATION
      HashMap<String ,Integer> map = new HashMap<>();

//      INSERTION

        map.put("India" ,120);
        map.put("China" , 150);
        map.put("us" ,50);

        System.out.println(map);

//        updation in value
        map.put("China" , 200);
        System.out.println(map);

//        DELETION IN HASHMAP
        map.remove("us");
        System.out.println(map);

//        using loop for in hash map
//        case 1:
        for (Map.Entry<String , Integer> e: map.entrySet())
        {
            System.out.println(e.getKey());
            System.out.println(e.getValue());
        }

//        case 2:
        System.out.println("--------------------------");
        Set<String> keys= map.keySet();
        for (String key: keys)
        {
            System.out.println(key  + map.get(key));
        }

ArrayList<Integer> li= new ArrayList<>();
//        li.sort();
    }
}

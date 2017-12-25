import java.lang.Long;

public class HashMap
{
    private class Bucket
    {
        public String key = null;
        public String val = null;
    }

    private static int hashMapSize = 10240;
    private int count = 0;
    private Bucket[] hash = new Bucket[hashMapSize];
   
    //This would be defined in the base class 
    private int map(String key) throws Exception
    {
        if (key == null)
        {
            throw new Exception("Invalid value passed to map");
        }

        return 0 % hashMapSize;
    }

    private int find(String key) throws Exception 
    {
        int index = this.map(key);
        if (hash[index].key != null)
        {
            while (hash[index].key != null && hash[index].key != key)
            {
                index = (index++ % hashMapSize);
            }

            if (hash[index].key != key)
            {
                index = -1;
            }
        }

        return index;
    }

    public boolean contains(String key) throws Exception
    {
        return (find(key) >= 0);
    }

    public boolean delete(String key) throws Exception
    {
        boolean success = false;
        int index = find(key);

        if (index != -1)
        {
            count --;
            hash[index].key = null;
            hash[index].val = null;
            success = true;
        }

        return success;
    }

    public void insert(String key, String val) throws Exception
    {
        if (count < hashMapSize -1)
        {
            if (!this.contains(key))
            {
                this.hash[map(key)].key = key;
                this.hash[map(key)].val = val;
            }
            else
            { //use linear probing to find an empty bucket to insert in
                int index = map(key);
                while (hash[index].key != null)
                {
                    index = (index++ % hashMapSize); 
                }

                hash[index].key = key;
                hash[index].val = val;
            }
            count++;
        }
        else
        {
            //create a larger 2x hashmap
            hashMapSize *= 2;
            Bucket[] newHash = new Bucket[2*hashMapSize];

            //Copy everything to the new hashmap handling collisions
            for (int i=0; i<(hashMapSize/2); ++i)
            {
                if (hash[i].key != null)
                {
                    int ind = map(hash[i].key);
                    while (newHash[ind].key == null)
                    {
                        ind = (ind++ % hashMapSize);
                    }
                    newHash[ind].key = hash[i].key;
                    newHash[ind].val = hash[i].val;
                }
            }
            //change the reference to the new hashmap the GC will remove the old hash map (eventually...)
            hash = newHash;
        }
    }

    public String get(String key) throws Exception
    {
        String val = null;
        int ind = this.find(key);

        if (ind != -1)
        { val = hash[ind].val; }

        return val;
    }
};

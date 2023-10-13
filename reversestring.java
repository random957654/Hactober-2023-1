import java.util.*;
public class reverse
{
    private stack st;

    class stack
    {
        private Listnode top;
        private int length;
        class Listnode 
        {
            private char data;
            private Listnode next;
            public Listnode()
            {
                this.next = null;
            }
            public Listnode(char val)
            {
                this.data = val;
                this.next = null;
            }
        }

        stack()
        {
            top = null;
            length = 0;
        }
        public boolean isEmpty()
        {
            if(top == null)
                return true;
            else 
                return false;
        }
        public void push(char val)
        {
            Listnode temp = new Listnode(val);
            if(!isEmpty())
            {
                temp.next = top;
            }
            top = temp;
            length++;
        }
        public char pop()
        {
            if(isEmpty())
                return '-';
            else 
            {
                char res = top.data;
                top = top.next;
                length--;
                return res;
            }
        }
        public void peek()
        {
            if(!isEmpty())
            {
                System.out.println(top.data);
            }
        }
    }

    public reverse()
    {
        st = new stack();
    }

    public String reverse(String s)
    {
        String w = "";
        for(int i = 0; i < s.length(); i++)
        {
            char c = s.charAt(i);
            st.push(c);
        }
        for(int i = 0; i < s.length(); i++)
        {
            w = w + st.pop();
        }
        return w;
    }
    public static void main(String[] args)
    {
        reverse oss = new reverse();
        String s1 = "rock";
        System.out.println(oss.reverse(s1));
    }
}

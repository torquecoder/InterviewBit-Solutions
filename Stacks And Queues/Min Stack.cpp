stack<int> st;
stack<int> minst;

MinStack::MinStack() {
    while (!st.empty())
        st.pop();
    while (!minst.empty())
        minst.pop();
}

void MinStack::push(int x) {
    st.push(x);
    if (minst.empty())
        minst.push(x);
    else
        minst.push(min(x, minst.top()));
}

void MinStack::pop() {
    if (!st.empty())
    {
        st.pop();
        minst.pop();
    }
}

int MinStack::top() {
    if (st.empty())
        return -1;
    return st.top();
}

int MinStack::getMin() {
    if (minst.empty())
        return -1;
    return minst.top();
}

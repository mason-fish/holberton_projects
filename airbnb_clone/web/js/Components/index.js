import React from 'react';
import Header from 'js/Components/Header'
import LeftColumn from 'js/Components/LeftColumn'
import Content from 'js/Components/Content'
import Footer from 'js/Components/Footer'

// main table for joining smart components together.
const App = () => {
    return (
        <div>
            <Header />
            <LeftColumn />
            <Content />
            <Footer />
        </div>
    );
}

export default App; 
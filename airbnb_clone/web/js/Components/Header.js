import React from 'react';
import styles from 'styles/header.css'

export default class Header extends React.Component {
    render () {
        return (
            <header className={styles.header}>
                <img className={styles.logo} src="http://brookes.esnuk.org/sites/brookes.esnuk.org/default/files/partners/images/airbnb_0.png" />
                <div className={styles.rightSide}></div>
            </header>
        );
    }
}
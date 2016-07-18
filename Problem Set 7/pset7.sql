-- phpMyAdmin SQL Dump
-- version 4.0.10deb1
-- http://www.phpmyadmin.net
--
-- Client: 127.0.0.1
-- Généré le: Lun 04 Juillet 2016 à 08:51
-- Version du serveur: 5.5.49-0ubuntu0.14.04.1
-- Version de PHP: 5.5.9-1ubuntu4.17

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de données: `pset7`
--

-- --------------------------------------------------------

--
-- Structure de la table `history`
--

CREATE TABLE IF NOT EXISTS `history` (
  `id` int(10) unsigned NOT NULL,
  `type` varchar(10) COLLATE utf8_unicode_ci NOT NULL,
  `symbol` varchar(10) COLLATE utf8_unicode_ci NOT NULL,
  `shares` int(11) NOT NULL,
  `price` double NOT NULL,
  `date` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Contenu de la table `history`
--

INSERT INTO `history` (`id`, `type`, `symbol`, `shares`, `price`, `date`) VALUES
(11, 'bought', 'FREE', 50, 1.15, '2016-07-03 07:08:41'),
(11, 'bought', 'FREE', 500, 1.15, '2016-07-03 07:14:40'),
(11, 'bought', 'FB', 1, 114.19, '2016-07-03 07:15:31'),
(11, 'bought', 'FB', 2, 114.19, '2016-07-03 07:50:03'),
(11, 'sold', '', 550, 0, '2016-07-03 07:51:01'),
(11, 'sold', '', 3, 0, '2016-07-03 08:01:52'),
(11, 'bought', 'FREE', 50, 1.15, '2016-07-03 08:09:21'),
(11, 'sold', '', 50, 0, '2016-07-03 08:10:09'),
(11, 'bought', 'FREE', 100, 1.15, '2016-07-03 09:24:47'),
(13, 'bought', 'FREE', 5000, 1.15, '2016-07-03 09:49:53'),
(14, 'bought', 'FREE', 1000, 1.15, '2016-07-03 16:24:32'),
(14, 'bought', 'FB', 20, 114.19, '2016-07-03 16:24:49'),
(14, 'bought', 'GOOG', 9, 699.21, '2016-07-03 16:28:45'),
(14, 'bought', 'CAC', 6, 41.95, '2016-07-03 16:29:58'),
(14, 'bought', 'FREE', 15, 1.15, '2016-07-04 08:50:10'),
(14, 'bought', 'FREE', 3, 1.15, '2016-07-04 08:50:21');

-- --------------------------------------------------------

--
-- Structure de la table `stocks`
--

CREATE TABLE IF NOT EXISTS `stocks` (
  `id` int(10) unsigned NOT NULL,
  `symbol` varchar(5) COLLATE utf8_unicode_ci NOT NULL,
  `shares` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id`,`symbol`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Contenu de la table `stocks`
--

INSERT INTO `stocks` (`id`, `symbol`, `shares`) VALUES
(14, 'CAC', '6'),
(14, 'FB', '20'),
(14, 'FREE', '1018'),
(14, 'GOOG', '9');

-- --------------------------------------------------------

--
-- Structure de la table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `cash` decimal(65,4) unsigned NOT NULL DEFAULT '0.0000',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=16 ;

--
-- Contenu de la table `users`
--

INSERT INTO `users` (`id`, `username`, `hash`, `cash`) VALUES
(1, 'andi', '$2y$10$c.e4DK7pVyLT.stmHxgAleWq4yViMmkwKz3x8XCo4b/u3r8g5OTnS', '0.0000'),
(2, 'caesar', '$2y$10$0p2dlmu6HnhzEMf9UaUIfuaQP7tFVDMxgFcVs0irhGqhOxt6hJFaa', '0.0000'),
(3, 'eli', '$2y$10$COO6EnTVrCPCEddZyWeEJeH9qPCwPkCS0jJpusNiru.XpRN6Jf7HW', '0.0000'),
(4, 'hdan', '$2y$10$o9a4ZoHqVkVHSno6j.k34.wC.qzgeQTBHiwa3rpnLq7j2PlPJHo1G', '0.0000'),
(5, 'jason', '$2y$10$ci2zwcWLJmSSqyhCnHKUF.AjoysFMvlIb1w4zfmCS7/WaOrmBnLNe', '0.0000'),
(6, 'john', '$2y$10$dy.LVhWgoxIQHAgfCStWietGdJCPjnNrxKNRs5twGcMrQvAPPIxSy', '0.0000'),
(7, 'levatich', '$2y$10$fBfk7L/QFiplffZdo6etM.096pt4Oyz2imLSp5s8HUAykdLXaz6MK', '0.0000'),
(8, 'rob', '$2y$10$3pRWcBbGdAdzdDiVVybKSeFq6C50g80zyPRAxcsh2t5UnwAkG.I.2', '0.0000'),
(9, 'skroob', '$2y$10$395b7wODm.o2N7W5UZSXXuXwrC0OtFB17w4VjPnCIn/nvv9e4XUQK', '0.0000'),
(10, 'zamyla', '$2y$10$UOaRF0LGOaeHG4oaEkfO4O7vfI34B1W23WqHr9zCpXL68hfQsS3/e', '0.0000'),
(14, 'oscar', '$2y$10$.qhE95IE8UZ8Qy20fpBLteprRf4LC0ifvxgBtFDph1C4dKMWG2gZi', '0.9100');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
